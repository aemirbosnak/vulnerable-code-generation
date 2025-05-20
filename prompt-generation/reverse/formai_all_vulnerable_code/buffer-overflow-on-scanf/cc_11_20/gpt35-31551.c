//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the Unique Ebook Reader Program\n\n");
    printf("This program allows you to read your favourite ebooks with unique functionalities\n\n");

    FILE *fptr;
    char filename[100], c;
    int option, page_number = 1, bookmark = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);
  
    fptr = fopen(filename, "r");

    if (fptr == NULL)
   {
       printf("Error opening file");
       exit(1);
   }

    printf("\n\nPLEASE CHOOSE AN OPTION : \n");
    printf("\n1: Next Page");
    printf("\n2: Previous Page");
    printf("\n3: Bookmark Page");
    printf("\n4: Display Bookmark");
    printf("\n5: Exit");

    do{
    printf("\n\nEnter Your Choice : ");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
            printf("\n\n");
            while (page_number <= bookmark)
            {
                c = fgetc(fptr);
                if (c == '#')
                {
                    bookmark = 0;
                    break;
                }
                else if (c == '\n')
                {
                    page_number++;
                }
            }
            while (c != '\n')
            {
                printf("%c", c);
                c = fgetc(fptr);
            }
            page_number++;
            break;

        case 2:
            printf("\n\n");
            fseek(fptr, (-2) * sizeof(char), SEEK_CUR);
            while (page_number != bookmark)
            {
                c = fgetc(fptr);
                if (c == '#')
                {
                    bookmark = 0;
                    break;
                }
                else if (c == '\n')
                {
                    page_number--;
                }
                fseek(fptr, (-2) * sizeof(char), SEEK_CUR);
            }
            fseek(fptr, sizeof(char), SEEK_CUR);
            c = fgetc(fptr);
            while (c != '\n')
            {
                printf("%c", c);
                c = fgetc(fptr);
            }
            page_number--;
            break;

        case 3:
            bookmark = page_number;
            printf("\n\n***Bookmark Added***\n\n");
            break;

        case 4:
            printf("\n\n***Bookmark Page : %d***\n\n", bookmark);
            break;

        case 5:
            exit(0);

        default:
            printf("\n\n***Invalid Option***\n\n");
    }
    }while(option != 5);


    fclose(fptr);
    return 0;
}