//FormAI DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

//Structure of a node in the B-Tree
typedef struct BTreeNode{
    int *keys; //Array of keys present in the B-Tree node
    struct BTreeNode **C; //Array of pointers to child nodes
    int n; //Number of keys currently present in the node
    int leaf; //Whether the node is a leaf or not
}node;

//Function to create a new node for the B-Tree
node* createNode(int t){
    node *n = (node*)malloc(sizeof(node));
    n->keys = (int*)malloc(sizeof(int)*(2*t-1));
    n->C = (node**)malloc(sizeof(node*)*2*t);
    n->n = 0;
    n->leaf = 1;
    return n;
}

//Function to split a child node of the B-Tree
void splitChild(node *x, int i, int t){
    node *z = createNode(t);
    node *y = x->C[i];
    z->leaf = y->leaf;
    z->n = t-1;
    for(int j=0;j<t-1;j++){
        z->keys[j] = y->keys[j+t];
    }
    if(y->leaf==0){
        for(int j=0;j<t;j++){
            z->C[j] = y->C[j+t];
        }
    }
    y->n = t-1;
    for(int j=x->n;j>=i+1;j--){
        x->C[j+1] = x->C[j];
    }
    x->C[i+1] = z;
    for(int j=x->n-1;j>=i;j--){
        x->keys[j+1] = x->keys[j];
    }
    x->keys[i] = y->keys[t-1];
    x->n += 1;
}

//Function to insert in a non-full child of the B-Tree
void insertNodeNonFull(node *x, int k, int t){
    int i = x->n-1;
    if(x->leaf==1){
        while(i>=0 && k<x->keys[i]){
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n += 1;
    }
    else{
        while(i>=0 && k<x->keys[i]){
            i--;
        }
        i++;
        if(x->C[i]->n == 2*t-1){
            splitChild(x, i, t);
            if(k>x->keys[i]){
                i++;
            }
        }
        insertNodeNonFull(x->C[i], k, t);
    }
}

//Function to insert a key in the B-Tree
node* insertNode(node *root, int k, int t){
    if(root==NULL){
        node *root = createNode(t);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }
    if(root->n==2*t-1){
        node *s = createNode(t);
        s->leaf = 0;
        s->C[0] = root;
        splitChild(s, 0, t);
        int i=0;
        if(s->keys[0]<k){
            i++;
        }
        insertNodeNonFull(s->C[i], k, t);
        return s;
    }
    insertNodeNonFull(root, k, t);
    return root;
}

int main(){
    //Driver function to demonstrate the B-Tree Indexing System
    
    //Create a B-Tree
    node *root = NULL;
    int t, n, key;
    printf("Enter the order of the B-Tree: ");
    scanf("%d",&t);
    printf("Enter the number of keys to be inserted: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter key %d: ",i);
        scanf("%d",&key);
        root = insertNode(root, key, t);
    }
    printf("Keys in the B-Tree: ");
    //Printing the keys in the B-Tree
    for(int i=0;i<root->n;i++){
        printf("%d ",root->keys[i]);
    }
    printf("\n");
    return 0;
}