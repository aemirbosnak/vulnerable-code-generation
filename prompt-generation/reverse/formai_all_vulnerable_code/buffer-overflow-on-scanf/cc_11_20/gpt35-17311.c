//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include<stdio.h>
#include<string.h>

int main()
{
    char str1[50], str2[50], temp[50];
    int option, length1, length2, i, j;

    printf("Welcome to the String Manipulator!\n\n");
    printf("Enter your first string: ");
    fgets(str1, 50, stdin);
    length1 = strlen(str1);
    if(str1[length1-1] == '\n')
      str1[--length1] = '\0';

    printf("\nEnter your second string: ");
    fgets(str2, 50, stdin);
    length2 = strlen(str2);
    if(str2[length2-1] == '\n')
      str2[--length2] = '\0';

    do
    {
        printf("\nWhat would you like to do with your strings?\n\n");
        printf("1. Concatenate the strings\n");
        printf("2. Reverse the strings\n");
        printf("3. Compare the strings\n");
        printf("4. Sort the strings\n");
        printf("5. Exit the program\n\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar();

        switch(option)
        {
            case 1:
                strcat(str1, str2);
                printf("\nThe strings concatenated! Your result is: %s\n", str1);
                break;

            case 2:
                for(i=0; i<length1/2; i++){
                    temp[i] = str1[i];
                    str1[i] = str1[length1-1-i];
                    str1[length1-1-i] = temp[i];
                }
                for(j=0; j<length2/2; j++){
                    temp[j] = str2[j];
                    str2[j] = str2[length2-1-j];
                    str2[length2-1-j] = temp[j];
                }
                printf("\nThe strings have been reversed! Your result is: %s %s\n", str1, str2);
                break;

            case 3:
                if(strcmp(str1, str2) == 0)
                    printf("\nThe strings are the same!.\n");
                else
                    printf("\nThe strings are different.\n");
                break;

            case 4:
                printf("\nThe strings are being arranged in alphabetical order:\n");
                if(strcmp(str1, str2) > 0)
                {
                    strcpy(temp, str1);
                    strcpy(str1, str2);
                    strcpy(str2, temp);
                }
                printf("\nThe strings in alphabetical order are: %s %s\n", str1, str2);
                break;

            case 5:
                printf("\nThank you for using the String Manipulator!\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
        }

    }while(option != 5);

    return 0;
}