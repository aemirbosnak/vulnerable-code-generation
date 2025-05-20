//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main(){

    char name[50], email[50], contact[10];
    int age = 0;

    // Name validation
    printf("Enter your full name: ");
    scanf("%[^\n]%*c", name); // Reading string with spaces

    while (1){
        int flag = 0; // Flag to check for invalid characters
        for(int i=0; name[i]!='\0'; i++){
            if(!isalpha(name[i]) && name[i]!='.')
                flag = 1;
        }
        if(flag==0) // If no invalid characters, break the loop
            break;
        printf("Invalid input! Please enter only alphabets and '.'\n");
        printf("Enter your full name again: ");
        scanf("%[^\n]%*c", name);
    }

    // Age validation
    while (1){
        printf("Enter your age: ");
        scanf("%d", &age);

        if(age>=18 && age<=60) // Age limit set between 18 and 60
            break;

        printf("Invalid input! Please enter an age between 18 and 60\n");
    }

    // Email validation
    while(1){
        int flag = 0; // Flag to check for invalid characters
        printf("Enter your email address: ");
        scanf("%[^\n]%*c", email); // Reading string with spaces

        // Check for '@' symbol in the email address
        for(int i=0; email[i]!='\0'; i++){
            if(email[i]=='@'){
                flag = 1;
                break;
            }
        }

        if(flag==1) // If '@' found, break the loop
            break;

        printf("Invalid input! Please enter a valid email address\n");
    }

    // Contact validation
    while (1){
        int flag = 0; // Flag to check for invalid characters
        printf("Enter your contact number: ");
        scanf("%s", contact);

        // Check if the contact number contains only digits
        for(int i=0; contact[i]!='\0'; i++){
            if(!isdigit(contact[i])){
                flag = 1;
                break;
            }
        }

        if(flag==0) // If only digits found, break the loop
            break;

        printf("Invalid input! Please enter only digits in contact number\n");
    }

    printf("\nName : %s\n", name);
    printf("Age: %d\n", age);
    printf("Email : %s\n", email);
    printf("Contact Number : %s\n", contact);

    return 0;
}