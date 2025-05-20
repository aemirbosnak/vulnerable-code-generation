//FormAI DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition of a client
typedef struct{
    char name[30];
    unsigned int account_number;
    float balance;
}client;

//Function prototypes
client* create_client();
void add_client(client*);
void edit_client(client*);
void delete_client(client*);

client* clients[100]; //An array of maximum 100 clients
int num_clients = 0; //Total number of clients in the system

int main(){
    int choice;
    printf("\nWelcome to the Banking Record System!\n");

    do{
        printf("\nPlease choose an option:\n");
        printf("1. Add a new client\n");
        printf("2. Edit an existing client\n");
        printf("3. Delete a client\n");
        printf("4. View all clients\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_client(create_client());
                break;
            case 2:
                edit_client(create_client());
                break;
            case 3:
                delete_client(create_client());
                break;
            case 4:
                printf("\nName\tAccount Number\tBalance\n");
                for(int i=0; i<num_clients; i++){
                    printf("%s\t%d\t\t%.2f\n", clients[i]->name, clients[i]->account_number, clients[i]->balance);
                }
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

    }while(choice != 5);

    return 0;
}

//Function to create a new client
client* create_client(){
    client* new_client = (client*)malloc(sizeof(client));
    printf("\nEnter client name: ");
    scanf("%s", new_client->name);
    printf("Enter account number: ");
    scanf("%u", &(new_client->account_number));
    printf("Enter balance: ");
    scanf("%f", &(new_client->balance));
    return new_client;
}

//Function to add a client to the system
void add_client(client* new_client){
    clients[num_clients++] = new_client;
    printf("\nClient successfully added!\n");
}

//Function to edit a client's information
void edit_client(client* new_client){
    for(int i=0; i<num_clients; i++){
        if(clients[i]->account_number == new_client->account_number){
            strcpy(clients[i]->name, new_client->name);
            clients[i]->balance = new_client->balance;
            printf("\nClient information updated!\n");
            return;
        }
    }
    printf("\nClient not found.\n");
}

//Function to delete a client from the system
void delete_client(client* new_client){
    for(int i=0; i<num_clients; i++){
        if(clients[i]->account_number == new_client->account_number){
            free(clients[i]);
            clients[i] = clients[--num_clients];
            printf("\nClient successfully deleted!\n");
            return;
        }
    }
    printf("\nClient not found.\n");
}