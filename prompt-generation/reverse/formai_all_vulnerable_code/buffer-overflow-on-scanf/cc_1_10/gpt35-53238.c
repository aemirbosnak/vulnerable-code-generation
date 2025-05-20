//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PORT_RANGE 65535

typedef struct node{
    int port_num;
    struct node* next;
}Node;

void print_menu();
int is_valid_port(char*);
int is_valid_range(char*, char*, int*, int*);
Node* add_port(Node*, int);
void display_list(Node*);
void free_list(Node*);

int main(){
    printf("\n--- Recursive Firewall ---\n\n");
    Node* ports = NULL;
    int option, port, start, end;
    char port_input[6], start_input[6], end_input[6];

    do{
        print_menu();
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the port number: ");
                scanf("%s", port_input);
                if(is_valid_port(port_input)){
                    port = atoi(port_input);
                    ports = add_port(ports, port);
                    printf("Port %d added successfully!\n", port);
                }
                else{
                    printf("Error: Invalid port number!\n");
                }
                break;

            case 2:
                printf("Enter the start and end range: ");
                scanf("%s %s", start_input, end_input);
                if(is_valid_range(start_input, end_input, &start, &end)){
                    for(int i=start; i<=end; i++){
                        ports = add_port(ports, i);
                    }
                    printf("Ports %d-%d added successfully!\n", start, end);
                }
                else{
                    printf("Error: Invalid range!\n");
                }
                break;

            case 3:
                printf("List of allowed ports:\n");
                display_list(ports);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Error: Invalid option selected!\n");
                break;
        }
    }while(option!=4);

    free_list(ports);

    return 0;
}

// Prints the menu options
void print_menu(){
    printf("\nMenu Options:\n");
    printf("1. Add a single port\n");
    printf("2. Add a range of ports\n");
    printf("3. View all allowed ports\n");
    printf("4. Exit program\n");
    printf("\nEnter option: ");
}

// Checks if a given port string is valid
int is_valid_port(char* port_input){
    if(strlen(port_input)>5){
        return 0;
    }
    for(int i=0; i<strlen(port_input); i++){
        if(!isdigit(port_input[i])){
            return 0;
        }
    }
    int port = atoi(port_input);
    if(port<1 || port>PORT_RANGE){
        return 0;
    }
    return 1;
}

// Checks if a given range is valid and returns start and end integers
int is_valid_range(char* start_input, char* end_input, int* start, int* end){
    if(strlen(start_input)>5 || strlen(end_input)>5){
        return 0;
    }
    for(int i=0; i<strlen(start_input); i++){
        if(!isdigit(start_input[i])){
            return 0;
        }
    }
    for(int i=0; i<strlen(end_input); i++){
        if(!isdigit(end_input[i])){
            return 0;
        }
    }
    *start = atoi(start_input);
    *end = atoi(end_input);
    if(*start<1 || *start>PORT_RANGE || *end<1 || *end>PORT_RANGE || *start>*end){
        return 0;
    }
    return 1;
}

// Adds a port to the linked list
Node* add_port(Node* head, int port){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->port_num = port;
        head->next = NULL;
    }
    else{
        head->next = add_port(head->next, port);
    }
    return head;
}

// Displays the contents of the linked list
void display_list(Node* head){
    if(head == NULL){
        printf("No ports allowed!\n");
    }
    else{
        printf("%d ", head->port_num);
        display_list(head->next);
    }
}

// Frees the linked list memory
void free_list(Node* head){
    if(head != NULL){
        free_list(head->next);
        free(head);
    }
}