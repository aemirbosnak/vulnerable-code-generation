//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
//Welcome to the Surrealist C Phone Book!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int count;
    char name[50], address[200], phone[15];
    printf("How many contacts do you want to add?\n");
    scanf("%d", &count);

    for(int i=0;i<count;i++){
        printf("Please enter the name of the contact:\n");
        scanf("%s", name);
        printf("Please enter their address:\n");
        scanf("%s", address);
        printf("Please enter their phone number:\n");
        scanf("%s", phone);

        printf("Adding %s to the surreal phone book...\n", name);

        if(strlen(name)<5){
            printf("The name %s is not surreal enough to be included in our phone book. Please try again.\n", name);
            i--;
        }
        else{
            strcat(name, " (the ethereal)");
            printf("Name updated to %s...\n", name);

            int num_digits = 0;
            int num_letters = 0;
            for(int j=0;j<strlen(phone);j++){
                if(isdigit(phone[j])){
                    num_digits++;
                }
                if(isalpha(phone[j])){
                    num_letters++;
                }
            }

            if(num_digits<6 || num_letters>2){
                printf("The phone number %s is too normal for our surreal phone book. Please try again.\n", phone);
                i--;
            }

            else{
                printf("Contact added successfully!\n");
            }
        }
    }

    printf("Thank you for using the Surrealist C Phone Book. Please come again!\n");

    return 0;
}