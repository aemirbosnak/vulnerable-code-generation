//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char full_name[100], email[100], phone[20], address[100];
    int age;

    printf("Enter Full Name: ");
    fgets(full_name, sizeof(full_name), stdin);
    full_name[strlen(full_name) - 1] = '\0'; // removes newline character

    // validating name
    for(int i = 0; i < strlen(full_name); i++){
        if(!isalpha(full_name[i]) && full_name[i] != ' '){
            printf("Invalid input. Full name should only contain alphabets [a-z, A-Z] and space.\n");
            return 1;
        }
    }

    printf("Enter Email Address: ");
    fgets(email, sizeof(email), stdin);
    email[strlen(email) - 1] = '\0'; // removes newline character

    // validating email
    if(strchr(email, '@') == NULL || strchr(email, '.') == NULL){
        printf("Invalid Email Address. Must have '@' and '.' symbols.\n");
        return 1;
    }

    printf("Enter Phone Number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strlen(phone) - 1] = '\0'; // removes newline character

    // validating phone number
    for(int i = 0 ; i < strlen(phone) ; i++)
    {
        if(!isdigit(phone[i]) && phone[i] != '-'){
            printf("Invalid Phone Number. Must contain only digits and '-' symbols.\n");
            return 1;
        }
    }

    printf("Enter Address: ");
    fgets(address, sizeof(address), stdin);
    address[strlen(address) - 1] = '\0'; // removes newline character

    printf("Enter Age: ");
    scanf("%d", &age);

    // validating age
    if(age < 0 || age > 130)
    {
        printf("Invalid Age. Age should be between 0 and 130.\n");
        return 1;
    }

    printf("\nData Validation Successful.\n");

    return 0;
}