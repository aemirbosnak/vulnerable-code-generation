//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void createFile(FILE *file);
void writeToFile(FILE *file);
void readFromFile(FILE *file);
void appendToFile(FILE *file);

int main() {
    char filename[50];
    int choice;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    do {
        printf("\n\nFile Handling Menu\n");
        printf("1. Create a new file\n");
        printf("2. Write to file\n");
        printf("3. Read from file\n");
        printf("4. Append to file\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(file);
                break;
            case 2:
                writeToFile(file);
                break;
            case 3:
                readFromFile(file);
                break;
            case 4:
                appendToFile(file);
                break;
            case 5:
                printf("Exiting program...\n");
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice\n");
        }

    } while (choice!= 5);

    return 0;
}

// function to create a new file
void createFile(FILE *file) {
    printf("\nEnter the text to write to the file: ");
    char text[100];
    scanf("%[^\n]s", text);

    fprintf(file, "%s", text);
    printf("\nFile created successfully!\n");
}

// function to write to a file
void writeToFile(FILE *file) {
    printf("\nEnter the text to write to the file: ");
    char text[100];
    scanf("%[^\n]s", text);

    fseek(file, 0L, SEEK_END);
    fprintf(file, "%s", text);
    printf("\nText written to file successfully!\n");
}

// function to read from a file
void readFromFile(FILE *file) {
    rewind(file);
    char ch;

    while ((ch = fgetc(file))!= EOF) {
        printf("%c", ch);
    }
}

// function to append to a file
void appendToFile(FILE *file) {
    printf("\nEnter the text to append to the file: ");
    char text[100];
    scanf("%[^\n]s", text);

    fseek(file, 0L, SEEK_END);
    fprintf(file, "%s", text);
    printf("\nText appended to file successfully!\n");
}