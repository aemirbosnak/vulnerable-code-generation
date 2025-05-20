//FormAI DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char* data;                             
    struct Node* next;                       
}node;                                        

void insert(node **front, node **rear, char *ebook){     
    node *temp = (node*)malloc(sizeof(node));         
    temp->data = ebook;                              
    temp->next = NULL;                                 
    if(*front == NULL){                              
        *front = *rear = temp;
    }
    else{
        (*rear)->next = temp;                   
        *rear = temp;                               
    }
}

int main(){
    node *front = NULL, *rear = NULL;            
    char title[50], author[50], option;           
    int pages, year;                                  

    printf("Welcome to the Ebook reader!\n\n");

    do{
        printf("Please enter the title of the Ebook: ");
        scanf(" %[^\n]s", title);                     

        printf("Please enter the author of the Ebook: ");      
        scanf(" %[^\n]s", author);                   

        printf("Please enter the number of pages in the Ebook: ");
        scanf("%d", &pages);                         

        printf("Please enter the year the Ebook was published: ");
        scanf("%d", &year);                          

        char *ebook = (char*)malloc(sizeof(char)*(strlen(title)+strlen(author)+20));          

        sprintf(ebook, "%s, by %s (%d pages, %d)\n", title, author, pages, year);          
        insert(&front, &rear, ebook);                                                          

        printf("Successfully added to Ebook list. Would you like to add another Ebook? (y/n): ");
        scanf(" %c", &option);
    }while(option == 'y' || option == 'Y');

    printf("\nHere is the list of Ebooks you added:\n");
    node *temp = front;                                     
    while(temp != NULL){                                    
        printf("%s", temp->data);                            
        temp = temp->next;                                 
    }

    node *curr, *prev = NULL;
    int choice;
    do{
        printf("\n\nEnter the number of the Ebook you want to read (1-%d): ", pages);
        scanf("%d", &choice);
        if(choice <= pages && choice >= 1){
            curr = front;                             
            for(int i=1;i<choice;i++){            
                prev = curr;                      
                curr = curr->next;                
            }
            printf("\nThe Ebook you chose is: %s\n\n", curr->data);
            prev->next = curr->next;                    
            free(curr->data);                           
            free(curr);                                 
            pages--;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }while(choice > 0);     

    temp = front;                                         
    while(temp != NULL){                                   
        curr = temp;                                        
        temp = temp->next;                                 
        free(curr->data);                                  
        free(curr);                                         
    }

    return 0;                                                
}