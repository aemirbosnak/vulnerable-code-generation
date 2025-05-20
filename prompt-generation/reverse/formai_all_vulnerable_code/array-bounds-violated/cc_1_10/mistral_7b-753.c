//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

#define TRUE    1
#define FALSE   0

#define HAUNTED_HOUSE_FILE "/dev/random"
#define MAX_RANDOM_BYTES 256
#define MAX_CHARS 256
#define MAX_LINES 13
#define MAX_LINE_LENGTH 80
#define MIN_DELAY 100
#define MAX_DELAY 5000

typedef struct {
    char name[MAX_CHARS];
    int age;
    float weight;
} Person;

void sigint_handler(int sig) {
    printf("\nExiting program due to user interrupt...\n");
    exit(0);
}

void print_haunted_house_line(int line_number) {
    int fd = open(HAUNTED_HOUSE_FILE, O_RDONLY);
    char random_bytes[MAX_RANDOM_BYTES];
    read(fd, random_bytes, MAX_RANDOM_BYTES);
    close(fd);

    int line_length = 0;
    char line[MAX_LINE_LENGTH];
    line[line_length++] = '|';

    for (int i = 0; i < line_number; i++) {
        line[line_length++] = ' ';
        line[line_length++] = '*';
        line[line_length++] = ' ';
    }

    int bytes_read = 0;
    while (bytes_read < MAX_CHARS - line_length - 2) {
        line[line_length++] = random_bytes[bytes_read];
        bytes_read++;
    }

    line[line_length++] = '|';

    printf("\033[1;%dm%s\033[0m\n", (line_number % 2 == 0) ? 31 : 34, line);
}

void print_person(Person person) {
    printf("\nName: %s", person.name);
    printf("\nAge: %d", person.age);
    printf("\nWeight: %.2f\n", person.weight);
}

int main() {
    signal(SIGINT, sigint_handler);

    srand(time(NULL));

    Person people[MAX_LINES];

    for (int i = 0; i < MAX_LINES; i++) {
        int name_length = rand() % (MAX_CHARS / 2) + (MAX_CHARS / 4);
        people[i].age = rand() % 120 + 18;
        people[i].weight = (float) (rand() % 100 + 50) / 10.0;

        printf("Enter name for person %d (max %d characters): ", i + 1, name_length);
        fgets(people[i].name, MAX_CHARS, stdin);
        people[i].name[strlen(people[i].name) - 1] = '\0';
    }

    printf("\nHaunted House\n");

    for (int i = 0; i < MAX_LINES; i++) {
        print_haunted_house_line(i);
        usleep(rand() % (MAX_DELAY - MIN_DELAY) + MIN_DELAY);
    }

    printf("\nPeople in the Haunted House:\n");

    for (int i = 0; i < MAX_LINES; i++) {
        usleep(rand() % (MAX_DELAY / 2) + MIN_DELAY);
        print_person(people[i]);
    }

    return 0;
}