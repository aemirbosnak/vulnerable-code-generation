//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ebook{
    char title[100];
    char author[50];
    char genre[20];
    char content[1000];
};

void add_ebook(struct ebook *ebook){
    printf("Enter the title of the eBook: ");
    scanf("%[^\n]", ebook->title);
    printf("Enter the author of the eBook: ");
    scanf("%[^\n]", ebook->author);
    printf("Enter the genre of the eBook: ");
    scanf("%[^\n]", ebook->genre);
    printf("Enter the content of the eBook: ");
    scanf("%[^\n]", ebook->content);
}

void display_ebook(struct ebook ebook){
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Genre: %s\n", ebook.genre);
    printf("Content:\n%s", ebook.content);
}

int main(){
    int choice, i;
    struct ebook ebook[100];

    while(1){
        printf("1. Add eBook\n2. Display eBook\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_ebook(&ebook[i]);
                i++;
                break;
            case 2:
                printf("Enter the index of the eBook to be displayed: ");
                scanf("%d", &i);
                display_ebook(ebook[i-1]);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}