//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define SIZE 100
#define INT_SIZE sizeof(int)

typedef struct {
    int id;
    char name[50];
} Person;

int main() {
    int i, j, fd;
    char *ptr;
    Person *persons;
    Person new_person;

    fd = open("people.bin", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ftruncate(fd, SIZE * INT_SIZE);
    persons = mmap(NULL, SIZE * INT_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (persons == MAP_FAILED) {
        perror("Error mmap-ing file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < SIZE; i++) {
        printf("Enter ID for person %d: ", i + 1);
        scanf("%d", &new_person.id);
        fflush(stdin);

        printf("Enter name for person %d: ", i + 1);
        fgets(new_person.name, sizeof(new_person.name), stdin);
        new_person.name[strcspn(new_person.name, "\n")] = '\0';

        *(persons + i) = new_person;
    }

    close(fd);
    munmap(persons, SIZE * INT_SIZE);

    fd = open("people.bin", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ptr = mmap(NULL, SIZE * INT_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Error mmap-ing file");
        exit(EXIT_FAILURE);
    }

    printf("\nList of people:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < strlen((*(persons + i)).name); j++) {
            putchar(((*(persons + i)).name)[j]);
        }
        printf(" - ID: %d\n", (*(persons + i)).id);
    }

    close(fd);
    munmap(ptr, SIZE * INT_SIZE);

    return 0;
}