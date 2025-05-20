//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 100
#define FILENAME "curious_database.dat"

struct record {
    char name[30];
    int age;
    float gpa;
};

int main() {
    int fd, i;
    struct record data;

    fd = open(FILENAME, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    printf("Welcome to the Curious Database Simulation!\n");
    printf("Here, you can store and retrieve records of your curious friends.\n");
    printf("Let's begin!\n");

    for (i = 0; i < SIZE; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", data.name);
        printf("Enter age: ");
        scanf("%d", &data.age);
        printf("Enter GPA: ");
        scanf("%f", &data.gpa);

        if (write(fd, &data, sizeof(struct record)) != sizeof(struct record)) {
            perror("Error writing to file");
            exit(1);
        }

        printf("Record saved successfully!\n");
    }

    close(fd);

    fd = open(FILENAME, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        exit(1);
    }

    printf("\nCurious Friends Database:\n");

    while (read(fd, &data, sizeof(struct record)) > 0) {
        printf("Name: %s\n", data.name);
        printf("Age: %d\n", data.age);
        printf("GPA: %.2f\n", data.gpa);
    }

    close(fd);

    fd = open(FILENAME, O_RDWR);
    if (fd < 0) {
        perror("Error opening file for updating");
        exit(1);
    }

    lseek(fd, (SIZE - 1) * sizeof(struct record), SEEK_SET);

    printf("\nEnter the name of the friend you want to update: ");
    scanf("%s", data.name);

    printf("Enter new age: ");
    scanf("%d", &data.age);

    if (write(fd, &data, sizeof(struct record)) != sizeof(struct record)) {
        perror("Error writing to file");
        exit(1);
    }

    close(fd);

    printf("\nFriend record updated successfully!\n");

    return 0;
}