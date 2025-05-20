//FormAI DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book{        //Structure for the Book
    char book_name[30];
    char author[30];
    char publisher[30];
    int year;
    float price;
};

void display_book(struct book b){   //Function to Display the Book Information
    printf("\n\nBook Name: %s\n",b.book_name);
    printf("Author Name: %s\n",b.author);
    printf("Publisher Name: %s\n",b.publisher);
    printf("Publication Year: %d\n",b.year);
    printf("Price: %.2f\n\n",b.price);
}

void display_menu(){       //Function to Display the Main Menu
    printf("************Welcome to the E-Book Reader**************\n");
    printf("1. Add Book\n");
    printf("2. Display Book\n");
    printf("3. Exit\n");
}

int main(){
    int choice;
    struct book b;          //Creating a Book object
    FILE *fp;               //Creating a file pointer
    char filename[30];      //To Store Name of the Ebook file

    while(1){               //Infinite loop

        display_menu();     //Display the Main Menu
        printf("Enter your choice: ");
        scanf("%d",&choice);    //Reading User Input

        switch(choice){

            case 1:             //Add a New Book to the Ebook Reader
                printf("\nEnter the Name of the Book: ");
                getchar();
                fgets(b.book_name,30,stdin);

                printf("Enter the Name of the Author: ");
                fgets(b.author,30,stdin);

                printf("Enter the Name of the Publisher: ");
                fgets(b.publisher,30,stdin);

                printf("Enter the Year of Publication: ");
                scanf("%d",&b.year);

                printf("Enter the Price: ");
                scanf("%f",&b.price);

                printf("\nBook Added Successfully!");

                fp = fopen("ebook.txt","a");      //Opening the Ebook file in Append Mode

                fprintf(fp,"%s\n%s\n%s\n%d\n%.2f\n",b.book_name,b.author,b.publisher,b.year,b.price);
                fclose(fp);         //Closing the Ebook file

                break;

            case 2:             //Display all the Books in the Ebook Reader
                fp = fopen("ebook.txt","r");       //Opening the Ebook file in Read Mode

                if(fp==NULL){           //Checking if the Ebook file exists
                    printf("\nError Reading File!");
                    exit(0);
                }

                while(fgets(b.book_name,30,fp)){        //Loop till end of file
                    fgets(b.author,30,fp);
                    fgets(b.publisher,30,fp);
                    fscanf(fp,"%d",&b.year);
                    fscanf(fp,"%f",&b.price);
                    display_book(b);          //Displaying the Book Information
                }

                fclose(fp);         //Closing the Ebook file
                break;

            case 3:             //Exit from the Ebook Reader
                printf("\nThank you for using the E-Book Reader!");
                exit(0);

            default:            //Default action for any other input
                printf("\nInvalid Input! Try again.");
        }
    }

    return 0;
}