//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

// function to extract the words from given string and display them
void displayWords(char *str) {
    char *token;
    printf("Words in String:\n");
    token = strtok(str, " ");

    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

// function to count the total number of vowels in given string
int countVowels(char *str) {
    int vowels = 0;
    for(int i=0; i<strlen(str); i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            vowels++;
    }
    return vowels;
}

// function to reverse the given string
void reverseString(char *str) {
    int len=strlen(str);

    for(int i=0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0;  // remove newline character at the end

    int choice;
    do {
        printf("\nWhat would you like to do with the string?\n1. Display words\n2. Count vowels\n3. Reverse string\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayWords(str);
                break;
            case 2:
                printf("Total vowels: %d\n", countVowels(str));
                break;
            case 3:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice!=4);

    return 0;
}