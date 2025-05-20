//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define STR_LEN 100

//Defining the structure for Database Indexing
struct student{
    int id;
    char name[STR_LEN];
    float cgpa;
};
typedef struct student Student;

//Defining the structure for B-Tree
struct b_tree_node{
    int count;
    Student *data[MAX+1];
    struct b_tree_node *child[MAX+1];
};
typedef struct b_tree_node BTreeNode;

//Function to create a new node in B-Tree
BTreeNode *createNode(Student *student) {
    BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->count = 1;
    newNode->data[1] = student;
    int i;
    for(i=0; i<=MAX; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

//Function to add a student in B-Tree
BTreeNode *addStudent(BTreeNode *root, Student *student) {
    if(root == NULL) {
        return createNode(student);
    }
    else {
        if(root->count < MAX) {
            int i = root->count;
            while(i>=1 && student->id < root->data[i]->id) {
                root->data[i+1] = root->data[i];
                i--;
            }
            root->data[i+1] = student;
            root->count++;
            return root;
        }
        else {
            int i = root->count;
            while(i>=1 && student->id < root->data[i]->id) {
                i--;
            }
            if(student->id > root->data[i]->id) {
                i++;
            }
            BTreeNode *splitNode = createNode(NULL);
            int j;
            for(j=i+1; j<=MAX; j++) {
                splitNode->data[j-i] = root->data[j];
                splitNode->child[j-i] = root->child[j];
            }
            splitNode->count = MAX - i;
            root->count = i;
            if(student->id > root->data[i]->id) {
                i++;
            }
            int k;
            for(j=MAX-1,k=0; j>=i; j--,k++) {
                root->data[j+1] = root->data[j];
                root->child[k+1] = root->child[k];
            }
            root->data[i] = student;
            root->child[k+1] = splitNode;
            return root;
        }
    }
}

//Function to search the B-Tree and return the student with given ID
Student *searchStudent(BTreeNode *root, int id) {
    if(root == NULL) {
        return NULL;
    }
    else {
        int i;
        for(i=1; i<=root->count; i++) {
            if(id == root->data[i]->id) {
                return root->data[i];
            }
            else if(id < root->data[i]->id) {
                return searchStudent(root->child[i-1], id);
            }
        }
        return searchStudent(root->child[i-1], id);
    }
}

//Function to traverse and print the B-Tree - Inorder Traversal
void printTree(BTreeNode *root) {
    if(root != NULL) {
        int i;
        for(i=0; i<root->count; i++) {
            printTree(root->child[i]);
            printf("ID : %d   Name : %s   CGPA : %.2f", root->data[i+1]->id, root->data[i+1]->name, root->data[i+1]->cgpa);
            printf("\n");
        }
        printTree(root->child[i]);
    }
}

int main() {

    BTreeNode *root = NULL;
    int choice, id;
    char name[STR_LEN];
    float cgpa;
    Student *student;

    do {
        printf("\n1. Add Student\n2. Search Student\n3. Print Database\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: //Add Student
                student = (Student*)malloc(sizeof(Student));
                printf("\nEnter the Student ID : ");
                scanf("%d", &id);
                student->id = id;
                printf("\nEnter the Name : ");
                scanf("%s", name);
                strcpy(student->name, name);
                printf("\nEnter the CGPA : ");
                scanf("%f", &cgpa);
                student->cgpa = cgpa;

                root = addStudent(root, student);
                break;

            case 2: //Search Student
                printf("\nEnter the Student ID to search : ");
                scanf("%d", &id);
                student = searchStudent(root, id);
                if(student == NULL) {
                    printf("\nStudent not found!");
                }
                else {
                    printf("\nStudent found!");
                    printf("\nID : %d   Name : %s   CGPA : %.2f", student->id, student->name, student->cgpa);
                    printf("\n");
                }
                break;

            case 3: //Print Database
                printf("\nDatabase Indexing System\n\n");
                printTree(root);
                break;

            case 4: //Exit
                printf("\nExiting Program!");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");

        }

    } while(choice != 4);

    return 0;
}