//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CHARS 100 // Maximum number of characters to be retrieved

//Function to capitalize all the alphabets in a given string
void strToUpper(char* str) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

//Function to check if two strings are equal
int strEqual(char* str1, char* str2) {
    return strcmp(str1, str2) == 0 ? 1 : 0;
}

int main() {
    char fileName[20];
    printf("Enter file name: ");
    fgets(fileName, 20, stdin);
    fileName[strlen(fileName) - 1] = '\0'; //Removing the newline character at the end
    strToUpper(fileName); //Capitalizing all the alphabets in the file name

    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Error opening file: %s\n", fileName);
        exit(1);
    }

    char data[MAX_CHARS + 1];
    int count = 0;
    int i;

    //Reading the first block of characters
    for(i = 0; i < MAX_CHARS; i++) {
        int c = fgetc(file);
        if(c == EOF) {
            data[i] = '\0'; //Adding the null terminator
            break;
        }
        data[i] = (char) c;

        //Checking for the end of line character
        if(c == '\n') {
            data[i + 1] = '\0'; //Adding the null terminator
            break;
        }
    }

    //Checking if the block of characters is equal to the recovery code
    if(strEqual(data, "DATA_RECOVERY_CODE")) {
        printf("Data recovery in progress...\n");
        char recoveredData[MAX_CHARS + 1];
        count = 0;

        //Recovering the rest of the data
        while(1) {
            //Reading the next block of characters
            for(i = 0; i < MAX_CHARS; i++) {
                int c = fgetc(file);
                if(c == EOF) {
                    recoveredData[count] = '\0'; //Adding the null terminator
                    break;
                }
                recoveredData[count++] = (char) c;

                //Checking for the end of line character
                if(c == '\n') {
                    recoveredData[count] = '\0'; //Adding the null terminator
                    break;
                }
            }
            if(strEqual(recoveredData, "END_OF_FILE")) {
                printf("Data recovery complete.\n");
                break;
            }
            //Appending the recovered data to an output file
            FILE* outputFile = fopen("recovered_data.txt", "a");
            if(outputFile == NULL) {
                printf("Error creating output file.\n");
                exit(1);
            }
            fputs(recoveredData, outputFile);
            fclose(outputFile);

            count = 0; //Resetting the count for the next block of characters
        }
    } else {
        printf("Invalid file format.\n");
    }

    fclose(file);
    return 0;
}