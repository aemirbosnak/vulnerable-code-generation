//FormAI DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct Node {
    char* word;
    int lineNo[1000];
    int count;
    struct Node *next;
} Node;

Node* addWord(Node* head, char* word, int lineNo);
void printList(Node* head);

int main() {
    char fileName[50];
    char line[1000];
    char word[WORD_LENGTH];
    Node* head = NULL;
    FILE* filePointer;
    int lineNo = 0;
     
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    filePointer = fopen(fileName, "r");
    if(filePointer == NULL) {
        printf("Unable to open file. Please check the file name and try again.\n");
        exit(1);
    }
    
    while(fgets(line, 1000, filePointer)) {
        lineNo++;
        int len = strlen(line);
        int i = 0, j = 0;
        while(i < len) {
            while(!isalnum(line[i]) && i < len) {
                i++; 
            }
            j = i;
            while(isalnum(line[j]) && j < len) {
                j++;
            }
            if(i != j) {
                int wordLen = j-i;
                if(wordLen > WORD_LENGTH) {
                    i = j;
                    continue;
                }
                strncpy(word, &line[i], wordLen);
                word[wordLen] = '\0';
                
                for(int k = 0; k < wordLen; k++) {
                    word[k] = tolower(word[k]);
                }
                head = addWord(head, word, lineNo);
                i = j;
            }
        }
    }
    fclose(filePointer);
    printf("\n**********************************\n");
    printf("List of misspelled words :\n");
    printf("**********************************\n");
    printList(head);
    return 0;
}

Node* addWord(Node* head, char* word, int lineNo) {
    if(head == NULL) {
        head = malloc(sizeof(Node));
        head->word = malloc(strlen(word) + 1);
        strcpy(head->word, word);
        head->lineNo[0] = lineNo;
        head->count = 1;
        head->next = NULL;
        return head;
    }
    Node* current = head;
    while(current) {
        if(strcmp(current->word, word) == 0) {
            current->count++;
            current->lineNo[current->count-1] = lineNo;
            return head;
        }
        if(current->next == NULL) {
            break;
        }
        current = current->next;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->word = malloc(strlen(word) + 1);
    strcpy(newNode->word, word);
    newNode->lineNo[0] = lineNo;
    newNode->count = 1;
    newNode->next = NULL;
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    while(head) {
        if(head->count == 1) {
            printf("%s on line %d\n", head->word, head->lineNo[0]);
        } else {
            printf("%s on lines: ", head->word);
            for(int i = 0; i < head->count; i++) {
                printf("%d ", head->lineNo[i]);
            }
            printf("\n");
        }
        head = head->next;
    }
}