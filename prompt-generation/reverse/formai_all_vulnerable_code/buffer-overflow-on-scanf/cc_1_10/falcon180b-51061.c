//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

int main()
{
    int choice;
    char ch;

    do {
        printf("Enter your choice:\n");
        printf("1. Lowercase pattern\n");
        printf("2. Uppercase pattern\n");
        printf("3. Mixed case pattern\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                scanf("%s",&ch);
                printf("Lowercase pattern:\n");
                printf("%s\n", &ch);
                break;

            case 2:
                printf("Enter a string: ");
                scanf("%s",&ch);
                printf("Uppercase pattern:\n");
                printf("%s\n", &ch);
                break;

            case 3:
                printf("Enter a string: ");
                scanf("%s",&ch);
                printf("Mixed case pattern:\n");
                printf("%s\n", &ch);
                break;

            default:
                printf("Invalid choice! ");
        }
    } while(choice!=0);

    return 0;
}