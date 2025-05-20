//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include<stdio.h>

int main()
{
    int choice;
    char hex[7], bin[33];

    do
    {
        printf("\nCOLOR CODE CONVERTER\n");
        printf("1. HEXADECIMAL TO BINARY\n");
        printf("2. BINARY TO HEXADECIMAL\n");
        printf("3. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nENTER HEXADECIMAL COLOR CODE: ");
                scanf("%s", hex);
                printf("\nBINARY COLOR CODE: ");
                for(int i=0; i<6; i++)
                {
                    printf("%d", hex[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("\nENTER BINARY COLOR CODE: ");
                scanf("%s", bin);
                printf("\nHEXADECIMAL COLOR CODE: ");
                for(int i=0; i<8; i++)
                {
                    printf("%c", bin[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("\nEXITING PROGRAM...\n");
                break;

            default:
                printf("\nINVALID CHOICE! TRY AGAIN\n");
        }
    }while(choice!=3);

    return 0;
}