//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    char name[MAX_SIZE];
    int age;
    int gender;
} Person;

void read_person(int fd, Person *person) {
    char buffer[MAX_SIZE];
    int bytes_read = 0;
    while (bytes_read < sizeof(Person)) {
        bytes_read += read(fd, buffer + bytes_read, MAX_SIZE - bytes_read);
    }
    memcpy(person, buffer, sizeof(Person));
}

void write_person(int fd, Person *person) {
    char buffer[MAX_SIZE];
    memcpy(buffer, person, sizeof(Person));
    write(fd, buffer, sizeof(Person));
}

int main() {
    int fd1, fd2;
    Person person1, person2;

    fd1 = open("person1.dat", O_RDWR | O_CREAT, 0666);
    if (fd1 == -1) {
        printf("Error opening person1.dat\n");
        exit(1);
    }

    fd2 = open("person2.dat", O_RDWR | O_CREAT, 0666);
    if (fd2 == -1) {
        printf("Error opening person2.dat\n");
        exit(1);
    }

    person1.name[0] = '\0';
    person1.age = 25;
    person1.gender = 1;
    write_person(fd1, &person1);

    read_person(fd2, &person2);
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    printf("Gender: %d\n", person2.gender);

    close(fd1);
    close(fd2);
    return 0;
}