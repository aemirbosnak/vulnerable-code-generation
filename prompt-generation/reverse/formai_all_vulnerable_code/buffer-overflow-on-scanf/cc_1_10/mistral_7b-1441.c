//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define FILE_NAME "data.txt"

struct Student {
    char name[50];
    int roll;
    float marks;
};

void readFile(FILE *file) {
    struct Student student;
    if (fread(&student, sizeof(student), 1, file) != 1) {
        perror("Error reading file");
        exit(1);
    }

    printf("Name: %s\n", student.name);
    printf("Roll: %d\n", student.roll);
    printf("Marks: %.2f\n", student.marks);
}

void writeFile(FILE *file, struct Student student) {
    if (fwrite(&student, sizeof(student), 1, file) != 1) {
        perror("Error writing to file");
        exit(1);
    }

    printf("Student data written to file successfully!\n");
}

int main() {
    FILE *file;
    struct Student student;
    int choice;

    file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("File not found, creating a new one...\n");
        file = fopen(FILE_NAME, "wb");
    }

    while (1) {
        printf("\n---------------------\n");
        printf("1. Add Student Data\n");
        printf("2. Display Student Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", student.name);
                printf("Enter Roll: ");
                scanf("%d", &student.roll);
                printf("Enter Marks: ");
                scanf("%f", &student.marks);

                writeFile(file, student);
                break;

            case 2:
                if (feof(file)) {
                    printf("No data found in file!\n");
                    break;
                }

                readFile(file);
                fseek(file, -sizeof(struct Student), SEEK_CUR);
                break;

            case 3:
                fclose(file);
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    fclose(file);
    return 0;
}