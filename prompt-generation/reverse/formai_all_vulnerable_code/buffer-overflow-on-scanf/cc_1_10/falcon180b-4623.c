//Falcon-180B DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Function to read the file
void read_file(FILE *fp) {
    char ch;
    char str[100];
    int count = 0;
    int i = 0;

    //Read the file character by character
    while ((ch = fgetc(fp))!= EOF) {
        //Check if the character is a letter
        if (isalpha(ch)) {
            //Convert the character to uppercase
            ch = toupper(ch);

            //Add the character to the string
            str[i] = ch;
            i++;
        }
    }

    //Add a null terminator to the string
    str[i] = '\0';

    //Print the string
    printf("The file contains the following text:\n%s\n", str);
}

//Function to write to the file
void write_file(FILE *fp) {
    char ch;

    //Prompt the user to enter text
    printf("Enter the text you want to write to the file: ");

    //Read the text from the user
    while ((ch = getchar())!= '\n') {
        //Write the character to the file
        fputc(ch, fp);
    }
}

int main() {
    FILE *fp;
    char choice;

    //Open the file in read mode
    fp = fopen("romantic_story.txt", "r");

    //Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    //Prompt the user to choose an option
    printf("Enter your choice:\n");
    printf("1. Read the file\n");
    printf("2. Write to the file\n");
    scanf("%c", &choice);

    //Perform the chosen operation
    switch (choice) {
        case '1':
            read_file(fp);
            break;
        case '2':
            write_file(fp);
            break;
        default:
            printf("Invalid choice.\n");
    }

    //Close the file
    fclose(fp);

    return 0;
}