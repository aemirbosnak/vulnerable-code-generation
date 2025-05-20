//FormAI DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

//Defining the structure of each node in the binary search tree
struct node
{
   int data;
   struct node *left,*right;
};

//Function to create a new node for insertion into the tree
struct node *newNode(int item)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = item;
   temp->left = temp->right = NULL;
   return temp;
}

//Function to add a new node into the tree in a binary search style
struct node* insert(struct node* node, int data)
{
   if (node == NULL) return newNode(data); //if the tree is empty, the new node becomes the root
   if (data < node->data)
      node->left  = insert(node->left, data);
   else if (data > node->data)
      node->right = insert(node->right, data);
   return node;
}

//Function to search for a specific value in the binary search tree
struct node* search(struct node* root, int key)
{
   if (root == NULL || root->data == key)
      return root;
   if (root->data < key)
      return search(root->right, key);
   return search(root->left, key);
}

//Function to traverse the binary search tree inorder and print the elements
void inorder(struct node *root)
{
   if (root != NULL)
   {
      inorder(root->left);
      printf("%d \n", root->data);
      inorder(root->right);
   }
}

int main()
{
   struct node *root = NULL;
   int choice, val;

   	
	while (1) {
		printf("1. Insertion\n");
        printf("2. Inorder Traversal\n");
        printf("3. Search\n");
        printf("4. Exit\n");
 
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch(choice) {
 
            case 1:
            
                while(1){
                    printf("Enter the value you want to insert (-1 to exit): ");
                    scanf("%d", &val);
                    if (val == -1){
                        break;
                    }
                    root = insert(root, val);
                }
                
                break;
 
            case 2:
            
                printf("Inorder Traversal is: ");
                inorder(root);
                printf("\n");
                
                break;
 
            case 3:
            
                printf("Enter the value you want to search: ");
                scanf("%d", &val);
                if(search(root, val) == NULL){
                    printf("Value not found!\n");
                }
                else{
                    printf("Value found in the tree!\n");
                }
                
                break;
 
            case 4:
            
                exit(0);
                break;
                
            default:
                printf("Please enter a valid choice!\n");
                break;
        }
    }
 
    return 0;
}