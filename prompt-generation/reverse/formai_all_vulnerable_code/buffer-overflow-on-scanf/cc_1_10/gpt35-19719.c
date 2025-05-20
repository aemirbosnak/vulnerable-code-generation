//FormAI DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 15
#define MAX_LINE_LEN (MAX_NAME_LEN + MAX_EMAIL_LEN + MAX_PHONE_LEN)

int main() {
    char filename[MAX_NAME_LEN];
    char line[MAX_LINE_LEN];
    FILE *file_pointer;

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Opening the file in "a+" mode, to append if it exists, otherwise create a new file
    file_pointer = fopen(filename, "a+");

    if (file_pointer == NULL) {
        printf("Unable to open file.");
        return 1; // returning non-zero to indicate failure
    }

    printf("Enter the name: ");
    scanf("%s", line);
    fputs(line, file_pointer);
    fputs(",", file_pointer);

    printf("Enter the email: ");
    scanf("%s", line);
    fputs(line, file_pointer);
    fputs(",", file_pointer);

    printf("Enter the phone number: ");
    scanf("%s", line);
    fputs(line, file_pointer);
    fputs("\n", file_pointer);

    rewind(file_pointer); // moving the file pointer to the beginning of the file

    printf("Contents of the file:\n");
    while (!feof(file_pointer)) { // checking for end of file
        fgets(line, MAX_LINE_LEN, file_pointer); // reading a line from the file
        printf("%s", line);
    }

    fclose(file_pointer); // closing the file
    return 0; // returning zero to indicate success
}