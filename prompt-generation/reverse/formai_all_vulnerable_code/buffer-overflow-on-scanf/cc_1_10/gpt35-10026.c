//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char str1[100], str2[100], temp[100];
    int opt;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    printf("\nWhat do you want to do ?");
    printf("\n1 - Swap the strings");
    printf("\n2 - Concatenate the strings");
    printf("\n3 - Compare the strings");
    printf("\n4 - Find the length of the strings");
    printf("\nEnter your choice (1, 2, 3 or 4): ");
    scanf("%d", &opt);

    switch(opt){
        case 1:
            //swap the strings
            strcpy(temp, str1);
            strcpy(str1, str2);
            strcpy(str2, temp);
            printf("\nAfter swapping, first string is: %s", str1);
            printf("\nAfter swapping, second string is: %s", str2);
            break;
        case 2:
            //concatenate the strings
            strcat(str1, str2);
            printf("\nAfter concatenation, the strings is: %s", str1);
            break;
        case 3:
            //compare the strings
            if(strcmp(str1, str2) == 0){
                printf("\nStrings are equal.");
            }
            else{
                printf("\nStrings are not equal.");
            }
            break;
        case 4:
            //find the length of the strings
            printf("\nThe length of first string is: %ld", strlen(str1));
            printf("\nThe length of second string is: %ld", strlen(str2));
            break;
        default:
            printf("\nInvalid choice! Please enter a valid choice (1, 2, 3 or 4).");
            break;
    }

    return 0;
}