//FormAI DATASET v1.0 Category: Music Library Management System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

struct Music{
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
    char genre[MAX_LENGTH];
    double duration;
    int rating;
};

typedef struct Music Music;

typedef struct Node{
    Music data;
    struct Node* next;
}Node;

Node* head = NULL;

void addMusic(){
    Music newMusic;
    printf("*******Enter the Music Details*******\n");
    printf("Title: ");
    scanf("%s",newMusic.title);
    printf("Artist: ");
    scanf("%s",newMusic.artist);
    printf("Album: ");
    scanf("%s",newMusic.album);
    printf("Year: ");
    scanf("%d",&newMusic.year);
    printf("Genre: ");
    scanf("%s",newMusic.genre);
    printf("Duration(in seconds): ");
    scanf("%lf",&newMusic.duration);
    printf("Rating(out of 10): ");
    scanf("%d",&newMusic.rating);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newMusic;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayMusic(){
    if(head==NULL){
        printf("No Music Found!");
    }
    else{
        Node* current = head;
        printf("*******Music List*******\n");
        while(current!=NULL){
            printf("Title: %s\n",current->data.title);
            printf("Artist: %s\n",current->data.artist);
            printf("Album: %s\n",current->data.album);
            printf("Year: %d\n",current->data.year);
            printf("Genre: %s\n",current->data.genre);
            printf("Duration: %lf seconds\n",current->data.duration);
            printf("Rating: %d/10\n\n\n",current->data.rating);
            current = current->next;
        }
    }
}

void searchMusic(){
    if(head==NULL){
        printf("No Music Found!");
    }
    else{
        char search[MAX_LENGTH];
        printf("Enter the music title you want to search: ");
        scanf("%s",search);
        Node* current = head;
        int found = 0;
        while(current!=NULL){
            if(strcmp(current->data.title,search)==0){
                found = 1;
                break;
            }
            current = current->next;
        }
        if(found){
            printf("The Music is found with the following details:\n");
            printf("Title: %s\n",current->data.title);
            printf("Artist: %s\n",current->data.artist);
            printf("Album: %s\n",current->data.album);
            printf("Year: %d\n",current->data.year);
            printf("Genre: %s\n",current->data.genre);
            printf("Duration: %lf seconds\n",current->data.duration);
            printf("Rating: %d/10\n\n\n",current->data.rating);
        }
        else{
            printf("The Music with the title '%s'not found!!\n",search);
        }
    }
}

void sortMusic(){
    if(head==NULL){
        printf("No Music Found!");
    }
    else{
        Node* current = head;
        Node* index = NULL;
        Music temp;
        while(current!=NULL){
            index = current->next;
            while(index!=NULL){
                if(strcmp(current->data.title,index->data.title)>0){
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
        printf("Music has been sorted successfully by title!\n");
    }
}

void editMusic(){
    if(head==NULL){
        printf("No Music Found!");
    }
    else{
        char search[MAX_LENGTH];
        printf("Enter the music title you want to edit: ");
        scanf("%s",search);
        Node* current = head;
        int found = 0;
        while(current!=NULL){
            if(strcmp(current->data.title,search)==0){
                found = 1;
                break;
            }
            current = current->next;
        }
        if(found){
            printf("*******Enter the New Music Details*******\n");
            printf("Title: ");
            scanf("%s",current->data.title);
            printf("Artist: ");
            scanf("%s",current->data.artist);
            printf("Album: ");
            scanf("%s",current->data.album);
            printf("Year: ");
            scanf("%d",&current->data.year);
            printf("Genre: ");
            scanf("%s",current->data.genre);
            printf("Duration(in seconds): ");
            scanf("%lf",&current->data.duration);
            printf("Rating(out of 10): ");
            scanf("%d",&current->data.rating);
            printf("The Music details has been updated successfully!\n");
        }
        else{
            printf("The Music with the title '%s'not found!!\n",search);
        }
    }
}

void deleteMusic(){
    if(head==NULL){
        printf("No Music Found!");
    }
    else{
        char search[MAX_LENGTH];
        printf("Enter the music title you want to delete: ");
        scanf("%s",search);
        Node* current = head;
        Node* prev = NULL;
        int found = 0;
        while(current!=NULL){
            if(strcmp(current->data.title,search)==0){
                found = 1;
                break;
            }
            prev = current;
            current = current->next;
        }
        if(found){
            if(current==head){
                head = current->next;
            }
            else{
                prev->next = current->next;
            }
            free(current);
            printf("The Music has been deleted successfully!\n");
        }
        else{
            printf("The Music with the title '%s' not found!!\n",search);
        }
    }
}

void saveMusic(){
    FILE* file = fopen("music.txt","w");
    if(file==NULL){
        printf("Unable to open the file!");
    }
    else{
        Node* current = head;
        while(current!=NULL){
            fprintf(file,"%s\n",current->data.title);
            fprintf(file,"%s\n",current->data.artist);
            fprintf(file,"%s\n",current->data.album);
            fprintf(file,"%d\n",current->data.year);
            fprintf(file,"%s\n",current->data.genre);
            fprintf(file,"%lf\n",current->data.duration);
            fprintf(file,"%d\n",current->data.rating);
            current = current->next;
        }
        printf("Music has been saved successfully!\n");
        fclose(file);
    }
}

void loadMusic(){
    FILE* file = fopen("music.txt","r");
    if(file==NULL){
        printf("Unable to open the file!");
    }
    else{
        char title[MAX_LENGTH];
        char artist[MAX_LENGTH];
        char album[MAX_LENGTH];
        int year;
        char genre[MAX_LENGTH];
        double duration;
        int rating;
        while(!feof(file)){
            fscanf(file,"%s\n",title);
            fscanf(file,"%s\n",artist);
            fscanf(file,"%s\n",album);
            fscanf(file,"%d\n",&year);
            fscanf(file,"%s\n",genre);
            fscanf(file,"%lf\n",&duration);
            fscanf(file,"%d\n",&rating);
            Music newMusic;
            strcpy(newMusic.title,title);
            strcpy(newMusic.artist,artist);
            strcpy(newMusic.album,album);
            newMusic.year = year;
            strcpy(newMusic.genre,genre);
            newMusic.duration = duration;
            newMusic.rating = rating;
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newMusic;
            newNode->next = NULL;
            if(head==NULL){
                head = newNode;
            }
            else{
                Node* current = head;
                while(current->next!=NULL){
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        printf("Music List has been loaded successfully!\n");
        fclose(file);
    }
}

void passwordProtection(){
    char password[9];
    int attempt=0;
    do{
    printf("Enter Password (8 characters max): ");
    scanf("%s",password);
    attempt++;
    }while(strcmp(password,"admin123")!=0 && attempt<3);
    if(attempt==3){
        printf("Authentication Failed!!\n");
    }
    else{
        printf("Authenticated Successfully!\n");
    }
}

int main(){
    passwordProtection();
    int choice;
    while(1){
        printf("***********************MENU***********************\n");
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Sort Music\n");
        printf("5. Edit Music\n");
        printf("6. Delete Music\n");
        printf("7. Save Music\n");
        printf("8. Load Music\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:addMusic();
                break;
            case 2:displayMusic();
                break;
            case 3:searchMusic();
                break;
            case 4:sortMusic();
                break;
            case 5:editMusic();
                break;
            case 6:deleteMusic();
                break;
            case 7:saveMusic();
                break;
            case 8:loadMusic();
                break;
            case 9:printf("Thank you for using the Music Library Management System!\n");
                exit(0);
            default:printf("Invalid choice!! Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}