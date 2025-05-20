//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

void readFile(char *filename);
void printBook(char *bookname,char *author, char *content);

int main(){
    char filename[MAX_LENGTH];
    char mainmenu[MAX_LENGTH];
    char bookname[MAX_LENGTH];
    char author[MAX_LENGTH];
    char content[MAX_LENGTH];
    char *book = NULL;
    int choice;

    printf("Welcome to the Ebook Reader!\n");
    printf("Please enter the name of the file containing the book:\n");
    scanf("%s",filename);
    readFile(filename);
    
    printf("Please enter the book name:\n");
    scanf("%s",bookname);
    printf("Please enter the author:\n");
    scanf("%s",author);
    
    printf("Would you like to save this book to the main menu? (1 for Yes, 0 for No):\n");
    scanf("%d",&choice);
    
    if(choice == 1){
        FILE *fp = fopen("mainmenu.txt","a");
        fprintf(fp,"%s %s\n",bookname, author);
        fclose(fp);
    }

    printBook(bookname,author,book); 

    return 0;
}

void readFile(char *filename){
    FILE *fp = fopen(filename,"r");
    char ch;

    if(fp == NULL){
        printf("Error: Cannot open file %s\n",filename);
        return;
    }

    while((ch = fgetc(fp))!=EOF){
        printf("%c", ch);
    }

    fclose(fp);
}

void printBook(char *bookname,char *author, char *content){
    printf("\n\n%s by %s\n",bookname,author);
    printf("-------------------------\n");
    printf("%s\n",content);
    printf("-------------------------\n");
}