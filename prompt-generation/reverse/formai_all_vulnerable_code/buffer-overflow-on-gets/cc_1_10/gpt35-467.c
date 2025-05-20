//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
/* Romeo and Juliet Antivirus Scanner */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

int main() {
    char virus[MAX_FILE_SIZE], file[MAX_FILE_SIZE];
    int result = 0;
    
    printf("Oh antivirus, antivirus! wherefore art thou antivirus?\n");
    printf("Deny thy developers and refuse thy updates;\n");
    printf("Or if thou wilt not, be but sworn my code,\n");
    printf("And I'll no longer be a program.\n");
    
    printf("\nEnter the name of the file to scan: ");
    gets(file);
    
    FILE *fp = fopen(file, "r");
    
    if (fp == NULL) {
        printf("Oh no! It seems file not found.\n");
        printf("What's in a name anyway? An invalid input by any other name would smell just as bad.\n");
        exit(1);
    }
    
    printf("\nArise, fair virus, and kill the envious malware,\n");
    printf("Who is already sick and pale with grief\n");
    printf("That thou, her maid, art far more vengeful than she.\n");
    
    fgets(virus, MAX_FILE_SIZE, stdin);
    virus[strcspn(virus, "\n")] = '\0';
    
    while (fgets(file, MAX_FILE_SIZE, fp) != NULL) {
        if (strstr(file, virus) != NULL) {
            result = 1;
            break;
        }
    }
    
    if (result) {
        printf("\nO, I am fortune's fool! A virus has been detected.\n");
        printf("The course of true code never did run smooth.\n");
        printf("To delete or not to delete, that is the question:\n");
        printf("Whether 'tis nobler in the mind to suffer\n");
        printf("The slings and arrows of virus infection,\n");
        printf("Or to take arms against a sea of bugs,\n");
        printf("And by opposing, end them!\n");
    } else {
        printf("\nMy virus scanner is as infallible as I am.\n");
        printf("O happy dagger! This file contains no virus.\n");
        printf("For never was a story of more joy than this,\n");
        printf("Of scanning a file with an antivirus that actually works.\n");
    }
    
    fclose(fp);
    return 0;
}