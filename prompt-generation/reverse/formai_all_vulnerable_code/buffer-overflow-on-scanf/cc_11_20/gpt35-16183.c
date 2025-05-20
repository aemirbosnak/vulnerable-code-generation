//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    printf("Welcome to the String Manipulator Program!\n\n");

    char str[100];
    char str2[100];
    char temp[100];
    int choice,i,j,l;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    do {
        printf("What do you want to do with the string?\n");
        printf("1. Reverse the string\n");
        printf("2. Copy the string\n");
        printf("3. Replace a character in the string\n");
        printf("4. Remove a character from the string\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nThe original string is: %s", str);
                strcpy(temp, str);
                int n = strlen(temp);
                for(i = 0; i < n/2; i++){
                    char temp1 = temp[i];
                    temp[i] = temp[n-i-1];
                    temp[n-i-1] = temp1;
                }
                printf("The reversed string is: %s\n", temp);
                break;

            case 2:
                printf("\nThe original string is: %s", str);
                strcpy(str2, str);
                printf("The copied string is: %s\n", str2);
                break;

            case 3:
                printf("\nThe original string is: %s", str);
                char old, new;
                printf("Enter the character you want to replace: ");
                scanf(" %c", &old);
                printf("Enter the new character: ");
                scanf(" %c", &new);
                int len = strlen(str);
                for(i=0; i<len; i++){
                    if(str[i] == old){
                        str[i] = new;
                    }
                }
                printf("The new string is: %s\n", str);
                break;

            case 4:
                printf("\nThe original string is: %s", str);
                char rem;
                printf("Enter the character you want to remove: ");
                scanf(" %c", &rem);
                l=0;
                len = strlen(str);
                for(i=0; i<len; i++){
                    if(str[i] != rem){
                        temp[l] = str[i];
                        l++;
                    }
                }
                temp[l] = '\0';
                strcpy(str, temp);
                printf("The new string is: %s\n", str);
                break;

            case 5:
                printf("\nThank you for using the string manipulator program!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}