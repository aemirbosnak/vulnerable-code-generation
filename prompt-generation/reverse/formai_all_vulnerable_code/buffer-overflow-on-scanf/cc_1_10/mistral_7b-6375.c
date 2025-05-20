//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question struct
typedef struct {
    int question_id;
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[10];
} Question;

// Student struct
typedef struct {
    int student_id;
    char name[50];
    int score;
} Student;

// Node struct for question linked list
typedef struct Node {
    Question q;
    struct Node *next;
} Node;

// Initialize question linked list
Node* init_question_list() {
    Node* head = NULL;
    return head;
}

// Add question to question linked list
void add_question(Node** head, Question q) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->q = q;
    new_node->next = *head;
    *head = new_node;
}

// Display menu
void display_menu() {
    printf("\n******************************************\n");
    printf("* Online Examination System Menu *\n");
    printf("******************************************\n");
    printf("* 1. Start Exam                    *\n");
    printf("* 2. Check Student Results         *\n");
    printf("* 3. Add Question                  *\n");
    printf("* 4. Exit                          *\n");
    printf("******************************************\n");
}

// Get user input and process menu option
int process_menu_option(Node** head, int choice) {
    int result = 0;
    switch (choice) {
        case 1:
            // Start exam logic here
            break;
        case 2:
            // Check student results logic here
            result = 1;
            break;
        case 3:
            // Add question logic here
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
    return result;
}

// Main function
int main() {
    Node* question_list = init_question_list();
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (process_menu_option(&question_list, choice) == 1) {
            // Student results logic here
            // ...
        }
    }

    return 0;
}