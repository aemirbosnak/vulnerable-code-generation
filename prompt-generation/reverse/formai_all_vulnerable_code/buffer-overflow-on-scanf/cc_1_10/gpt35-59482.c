//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[50];
    printf("Enter the name of the file to create: ");
    scanf("%s", file_name);

    FILE *file_ptr = fopen(file_name, "w");
    if(file_ptr == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("Enter some text to add to the file: ");
    char input_str[100];
    scanf("%s", input_str);
    fprintf(file_ptr, "%s\n", input_str);

    printf("Text successfully written to file!\n");

    fclose(file_ptr);

    printf("Would you like to read the file? (y/n): ");
    char read_choice;
    scanf(" %c", &read_choice);

    if(read_choice == 'y') {
        file_ptr = fopen(file_name, "r");
        if(file_ptr == NULL) {
            printf("Error opening the file.\n");
            exit(1);
        }

        char file_content[100];
        fscanf(file_ptr, "%[^\n]", file_content);
        printf("The file contains the following text:\n%s\n", file_content);

        fclose(file_ptr);
    }

    printf("Would you like to delete the file? (y/n): ");
    char del_choice;
    scanf(" %c", &del_choice);

    if(del_choice == 'y') {
        int status = remove(file_name);
        if(status == 0) {
            printf("File deleted successfully.\n");
        } else {
            printf("Error deleting the file.\n");
            exit(1);
        }
    }

    return 0;
}