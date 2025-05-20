//FormAI DATASET v1.0 Category: File handling ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the virtual library!\n");
    
    char bookName[20], authorName[20];
    int choice, numBooks=0;
    
    FILE *fp;
    
    //Opening the file in write mode
    fp = fopen("books.txt", "w");
    
    if(fp==NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    
    //Taking inputs and storing them in the file
    printf("\n\tEnter book name: ");
    scanf("%s", bookName);
    fprintf(fp, "Book Name: %s\n", bookName);

    printf("\n\tEnter author name: ");
    scanf("%s", authorName);
    fprintf(fp, "Author Name: %s\n\n", authorName);
    
    numBooks++;

    //Closing the file after writing
    fclose(fp);
    
    //Printing the contents of the file
    printf("\n\tBook added successfully.\n\n");
    
    //Taking input to view the books
    printf("\n\tEnter 1 to view all books or any other key to exit: ");
    scanf("%d", &choice);
    
    //Opening the file in read mode and displaying its contents
    if(choice==1){
        fp = fopen("books.txt", "r");
        
        if(fp==NULL){
            printf("Error opening file!\n");
            exit(1);
        }
        
        printf("\n\tList of books:\n\n");
        
        char c = fgetc(fp);
        while(c!=EOF){
            printf("%c", c);
            c = fgetc(fp);
        }
        
        fclose(fp);
    }
    
    printf("\n\tThank you for using our virtual library!\n");
    
    return 0;
}