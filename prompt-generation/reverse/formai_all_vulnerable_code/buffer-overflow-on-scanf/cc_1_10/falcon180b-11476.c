//Falcon-180B DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

int create_file(File *file) {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file->filename = strdup(filename);
    file->file = fopen(filename, "w");
    if (file->file == NULL) {
        printf("Error creating file\n");
        exit(1);
    }
    return 0;
}

int append_to_file(File *file) {
    printf("Enter text to append:\n");
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, MAX_LINE_LENGTH, stdin);
    fprintf(file->file, "%s", buffer);
    return 0;
}

int read_from_file(File *file) {
    char buffer[MAX_LINE_LENGTH];
    rewind(file->file);
    while (fgets(buffer, MAX_LINE_LENGTH, file->file)!= NULL) {
        printf("%s", buffer);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    File file;
    int choice;

    do {
        printf("\n\nWelcome to the Funny File Handler!\n");
        printf("Please choose an option:\n");
        printf("1. Create a new file\n");
        printf("2. Append to an existing file\n");
        printf("3. Read from a file\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create_file(&file);
            break;
        case 2:
            append_to_file(&file);
            break;
        case 3:
            read_from_file(&file);
            break;
        case 4:
            printf("Thanks for using the Funny File Handler! See you next time!\n");
            break;
        default:
            printf("Invalid option, please try again!\n");
        }
    } while (choice!= 4);

    return 0;
}