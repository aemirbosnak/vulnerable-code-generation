//FormAI DATASET v1.0 Category: String manipulation ; Style: mind-bending
#include<stdio.h>
#include<string.h>

//Function to reverse the string
void reverse_string(char *str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char name[100], surname[100], full_name[200], rev_full_name[200];

    //Get user input for the first name
    printf("Enter your first name: ");
    scanf("%s", name);

    //Get user input for the last name (surname)
    printf("Enter your last name (surname): ");
    scanf("%s", surname);

    //Concatenate the first and last name to form the full name
    snprintf(full_name, sizeof(full_name), "%s %s", name, surname);

    //Print the full name
    printf("\nYour full name is: %s\n", full_name);

    //Reverse the full name
    strcpy(rev_full_name, full_name);
    reverse_string(rev_full_name);

    //Print the reversed full name
    printf("Your name in reverse order is: %s\n", rev_full_name);

    //Convert each character of full name to binary code and print
    printf("Your name in binary code is: ");
    for(int i=0; i < strlen(full_name); i++) {
        printf("%c ", full_name[i]);
        for(int j=0; j < 8; j++) {
            printf("%d", (full_name[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");

    //Convert each character of full name to octal code and print
    printf("Your name in octal code is: ");
    for(int i=0; i < strlen(full_name); i++) {
        printf("%c ", full_name[i]);
        printf("%03o ", full_name[i]);
    }
    printf("\n");

    //Convert each character of full name to hexadecimal code and print
    printf("Your name in hexadecimal code is: ");
    for(int i=0; i < strlen(full_name); i++) {
        printf("%c ", full_name[i]);
        printf("%02x ", full_name[i]);
    }
    printf("\n");

    return 0;
}