//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(tolower(str[i])!= tolower(str[len-1-i])) {
            return 0;
        }
    }
    return 1;
}

// Function to scan a file for viruses
void scanFile(FILE* fp) {
    char line[1024];
    while(fgets(line, sizeof(line), fp)!= NULL) {
        int found = 0;
        char* virus1 = "I am a virus";
        char* virus2 = "You have been infected";
        char* virus3 = "Your computer is now mine";
        int virus1Len = strlen(virus1);
        int virus2Len = strlen(virus2);
        int virus3Len = strlen(virus3);
        for(int i=0; i<strlen(line); i++) {
            if(tolower(line[i]) == tolower(virus1[i%virus1Len])) {
                found = 1;
                break;
            }
        }
        if(!found) {
            for(int i=0; i<strlen(line); i++) {
                if(tolower(line[i]) == tolower(virus2[i%virus2Len])) {
                    found = 1;
                    break;
                }
            }
        }
        if(!found) {
            for(int i=0; i<strlen(line); i++) {
                if(tolower(line[i]) == tolower(virus3[i%virus3Len])) {
                    found = 1;
                    break;
                }
            }
        }
        if(found) {
            printf("Virus found in line: %s\n", line);
        }
    }
}

int main() {
    char fileName[256];
    printf("Enter the name of the file to scan: ");
    scanf("%s", fileName);
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    scanFile(fp);
    fclose(fp);
    return 0;
}