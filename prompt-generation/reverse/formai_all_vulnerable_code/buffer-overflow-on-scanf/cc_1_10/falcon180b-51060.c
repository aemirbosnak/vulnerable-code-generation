//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void create_file(FILE **file_ptr, char *filename);
void write_to_file(FILE *file_ptr, char *data);
void read_from_file(FILE *file_ptr);
void append_to_file(FILE *file_ptr, char *data);
void delete_file(FILE **file_ptr);

int main() {
    FILE *file_ptr;
    char filename[50] = "example.txt";
    char choice;
    int i;

    do {
        printf("\n\nEnter choice:\n1. Create file\n2. Write to file\n3. Read from file\n4. Append to file\n5. Delete file\n6. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                create_file(&file_ptr, filename);
                break;
            case '2':
                write_to_file(file_ptr, "Hello World!\n");
                fclose(file_ptr);
                break;
            case '3':
                file_ptr = fopen(filename, "r");
                read_from_file(file_ptr);
                fclose(file_ptr);
                break;
            case '4':
                file_ptr = fopen(filename, "a");
                append_to_file(file_ptr, "This is appended text.\n");
                fclose(file_ptr);
                break;
            case '5':
                delete_file(&file_ptr);
                break;
            case '6':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '6');

    return 0;
}

// Function to create a new file
void create_file(FILE **file_ptr, char *filename) {
    FILE *temp_file;

    temp_file = fopen(filename, "w");

    if(temp_file == NULL) {
        printf("Error creating file.\n");
        exit(1);
    } else {
        *file_ptr = temp_file;
        printf("File created successfully.\n");
    }
}

// Function to write data to a file
void write_to_file(FILE *file_ptr, char *data) {
    if(fwrite(data, strlen(data), 1, file_ptr)!= 1) {
        printf("Error writing to file.\n");
        exit(1);
    } else {
        printf("Data written to file successfully.\n");
    }
}

// Function to read data from a file
void read_from_file(FILE *file_ptr) {
    char ch;

    while((ch = fgetc(file_ptr))!= EOF) {
        printf("%c", ch);
    }
}

// Function to append data to a file
void append_to_file(FILE *file_ptr, char *data) {
    if(fwrite(data, strlen(data), 1, file_ptr)!= 1) {
        printf("Error appending to file.\n");
        exit(1);
    } else {
        printf("Data appended to file successfully.\n");
    }
}

// Function to delete a file
void delete_file(FILE **file_ptr) {
    remove(*file_ptr);
    printf("File deleted successfully.\n");
}