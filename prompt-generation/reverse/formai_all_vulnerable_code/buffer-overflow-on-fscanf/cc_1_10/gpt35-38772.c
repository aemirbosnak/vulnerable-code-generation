//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Node for the Linked List
typedef struct Node{
    char* word;
    int count;
    struct Node* next;
} Node;

//Function to add the word to our Linked List
void addToList(Node** head, char* word)
{
    //If the Linked List is empty, create a new node and add the word
    if(*head == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->word = strdup(word);
        newNode->count = 1;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        Node* temp = *head;
        int found = 0;

        //If the word is already present in the Linked List, update the count
        while(temp!=NULL)
        {
            if(strcmp(temp->word,word)==0)
            {
                found = 1;
                temp->count++;
                break;
            }
            temp = temp->next;
        }
        //If the word is not present in the Linked List, create a new node and add the word
        if(!found)
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->word = strdup(word);
            newNode->count = 1;
            newNode->next = *head;
            *head = newNode;
        }
    }
}

//Function to print the Linked List
void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%s : %d\n", head->word, head->count);
        head = head->next;
    }
}

//Main Function
int main(int argc, char* argv[])
{
    //Checking if the file name is provided as input
    if(argc!=2)
    {
        printf("Usage: ./freq filename\n");
        exit(1);
    }

    FILE* fp = fopen(argv[1], "r");

    //Checking if the file exists
    if(fp == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        exit(1);
    }

    Node* head = NULL;
    char word[100];

    //Reading the words from the file and adding them to the Linked List
    while(fscanf(fp, "%s", word) != EOF)
    {
        int len = strlen(word);
        int i;
        for(i=0;i<len;i++)
            word[i] = tolower(word[i]);
        addToList(&head, word);
    }

    fclose(fp);

    //Printing the word frequency count
    printList(head);

    return 0;
}