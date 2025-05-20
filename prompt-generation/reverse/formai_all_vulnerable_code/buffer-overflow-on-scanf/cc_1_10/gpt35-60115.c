//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char password[20];
	struct node* next;
}Node;

Node* head = NULL;

void addPassword(Node** headRef, char* password) {
	//Allocate memory for the new node
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	//Copy the password to the new node
	strcpy(newNode->password, password);
	
	//Set the next pointer to NULL
	newNode->next = NULL;

	//If the list is empty, set the head to the new node
	if (*headRef == NULL) {
		*headRef = newNode;
		return;
	}
	
	//Otherwise, traverse to the end of the list and add the new node
	Node* current = *headRef;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

void deletePassword(Node** headRef, int index) {
	//If the list is empty, do nothing
	if (*headRef == NULL) {
		return;
	}

	//If the head node needs to be deleted
	if (index == 0) {
		Node* temp = *headRef;
		*headRef = temp->next;
		free(temp);
		return;
	}

	//Otherwise, traverse to the node before the one to be deleted
	Node* current = *headRef;
	for (int i = 0; i < index - 1; i++) {
		if (current->next == NULL) {
			return; //The index is invalid
		}
		current = current->next;
	}

	//Delete the node at the given index
	Node* temp = current->next;
	current->next = temp->next;
	free(temp);
}

void printPasswords(Node* head) {
	//If the list is empty, do nothing
	if (head == NULL) {
		return;
	}

	//Otherwise, traverse the list and print each password
	Node* current = head;
	int index = 0;
	while (current != NULL) {
		printf("%d: %s\n", index, current->password);
		current = current->next;
		index++;
	}
}

int main() {
	int choice;
	char input[20];

	do {
		printf("1. Add password\n");
		printf("2. Remove password\n");
		printf("3. View passwords\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter the password to add: ");
				scanf("%s", input);
				addPassword(&head, input);
				break;

			case 2:
				printf("Enter the index of the password to remove: ");
				scanf("%d", &choice);
				deletePassword(&head, choice);
				break;

			case 3:
				printPasswords(head);
				break;

			case 4:
				printf("Goodbye!\n");
				break;

			default:
				printf("Invalid choice. Please try again.\n");
				break;
		}

	} while (choice != 4);

	return 0;
}