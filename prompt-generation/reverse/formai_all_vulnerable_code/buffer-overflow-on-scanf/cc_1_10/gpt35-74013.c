//FormAI DATASET v1.0 Category: Binary search trees ; Style: brave
#include<stdio.h>    
#include<stdlib.h>  
struct node  
{  
    int data;  
    struct node *left;   
    struct node *right;  
};  
struct node *root;  
void insert();  
void delete();  
void inorder(struct node*);  
void preorder(struct node*);  
void postorder(struct node*);  
int main ()  
{  
    int choice;   
    printf("\nBinary Tree Example - Data Structure in C\n");  
    while(1){  
        printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d",&choice);  
        switch(choice){  
            case 1: insert();  
                    break;  
            case 2: delete();  
                    break;  
            case 3: printf("\nInorder Traversal: ");  
                    inorder(root);  
                    break;  
            case 4: printf("\nPreorder Traversal: ");  
                    preorder(root);  
                    break;  
            case 5: printf("\nPostorder Traversal: ");  
                    postorder(root);  
                    break;  
            case 6: exit(0);  
                    break;  
            default: printf("\nInvalid Choice.\n");  
        }  
    }  
    return 0;  
}  
void insert()  
{  
    struct node *ptr,*parentptr=NULL;  
    ptr=(struct node*)malloc(sizeof(struct node));  
    if(ptr==NULL)  
    {  
        printf("\nOut of Memory Space.\n");  
        return;  
    }  
    printf("\nEnter the data value for new node: ");  
    scanf("%d",&ptr->data);  
    ptr->left=NULL;   
    ptr->right=NULL;  
    if(root==NULL)  
    {  
        root=ptr;  
        printf("\nNode inserted as root node.\n");  
        return;  
    }  
    else  
    {  
        parentptr=root;  
        while(parentptr!=NULL)  
        {  
            if(ptr->data>parentptr->data)  
            {  
                if(parentptr->right==NULL)  
                {  
                    parentptr->right=ptr;  
                    printf("\nNode inserted to right.\n");  
                    return;  
                }  
                else  
                    parentptr=parentptr->right;  
            }  
            else  
            {  
                if(parentptr->left==NULL)  
                {  
                    parentptr->left=ptr;  
                    printf("\nNode inserted to left.\n");  
                    return;  
                }  
                else  
                    parentptr=parentptr->left;  
            }  
        }  
    }  
}  
void delete()  
{  
    int x;  
    struct node *ptr,*parentptr,*suc,*psuc,*ptr1;  
    printf("\nEnter the value to be deleted: ");  
    scanf("%d",&x);  
    ptr=root;  
    parentptr=NULL;  
    while(ptr!=NULL)  
    {  
        if(x==ptr->data)  
            break;  
        else  
        {  
            parentptr=ptr;  
            if(x>ptr->data)  
                ptr=ptr->right;  
            else  
                ptr=ptr->left;  
        }  
    }  
    if(ptr==NULL)  
    {  
        printf("\nNode not found.\n");  
        return;  
    }  
    if(ptr->left==NULL && ptr->right==NULL)  
    {  
        if(parentptr!=NULL)  
        {  
            if(parentptr->left==ptr)  
                parentptr->left=NULL;  
            else  
                parentptr->right=NULL;  
        }  
        else  
            root=NULL;  
        printf("\nNode deleted.\n");  
        free(ptr);  
    }  
    else if(ptr->left!=NULL && ptr->right!=NULL)  
    {  
        psuc=ptr;  
        suc=ptr->right;  
        while(suc->left!=NULL)  
        {  
            psuc=suc;  
            suc=suc->left;  
        }  
        if(ptr!=root)  
        {  
            if(parentptr->left==ptr)  
                parentptr->left=suc;  
            else  
                parentptr->right=suc;  
        }  
        else  
            root=suc;  
        suc->left=ptr->left;  
        if(psuc!=ptr)  
        {  
            suc->right=ptr->right;  
            psuc->left=NULL;  
        }  
        printf("\nNode deleted.\n");  
        free(ptr);  
    }  
    else  
    {  
        if(ptr->left!=NULL)  
            ptr1=ptr->left;  
        else  
            ptr1=ptr->right;  
        if(ptr!=root)  
        {  
            if(parentptr->left==ptr)  
                parentptr->left=ptr1;  
            else  
                parentptr->right=ptr1;  
        }  
        else  
            root=ptr1;  
        printf("\nNode deleted.\n");  
        free(ptr);  
    }     
}  
void inorder(struct node *ptr)  
{  
    if(ptr!=NULL)  
    {  
        inorder(ptr->left);  
        printf("%d ",ptr->data);  
        inorder(ptr->right);  
    }  
}  
void preorder(struct node *ptr)  
{  
    if(ptr!=NULL)  
    {  
        printf("%d ",ptr->data);  
        preorder(ptr->left);  
        preorder(ptr->right);  
    }  
}  
void postorder(struct node *ptr)  
{  
    if(ptr!=NULL)  
    {  
        postorder(ptr->left);  
        postorder(ptr->right);  
        printf("%d ", ptr->data);  
    }  
}