//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

#define LEFT 0
#define RIGHT 1
#define SEEK 0
#define PUT 1
#define NO_SUCH_NODE -1

typedef struct BST
{
    int value ;
    struct BST *parent ;
    struct BST *adjacent[2] ;
}BST ;

BST* new_BST_node(int value)
{
    BST* node = (BST*)malloc(sizeof(BST)) ;
    if(node == NULL)
        printf("Fatal error: malloc failed!\n") ;
    node->value = value ;
    node->parent = NULL ;
    node->adjacent[LEFT] = NULL ;
    node->adjacent[RIGHT] = NULL ;
    return node ;
}

BST* find_target_node_depth_traversal(BST *root, int target)
{
    int count = 0 ;
    if(root == NULL)
        return NULL ;
    else if(target == root->value)
        return root ;
    else if(target < root->value)
        return find_target_node_depth_traversal(root->adjacent[LEFT],target) ;
    else if(target > root->value)
        return find_target_node_depth_traversal(root->adjacent[RIGHT],target) ;
}

BST* find_target_node_breadth_traversal(BST *root, int target)
{
    if(root==NULL)
        return NULL ;
    BST *queue[1000], *temp ;
    int front=0 , rear=-1 ;
    queue[++rear] = root ;
    while(front<=rear)
    {
        temp = queue[front++] ;
        if(target == temp->value)
            return temp ;
        if(temp->adjacent[LEFT]!=NULL)
            queue[++rear] = temp->adjacent[LEFT] ;
        if(temp->adjacent[RIGHT]!=NULL)
            queue[++rear] = temp->adjacent[RIGHT] ;
    }
    return NULL ;
}

BST* find_target_node_traversal(BST *root, int target, int method)
{
    if(method==SEEK)
        return find_target_node_depth_traversal(root,target) ;
    else if(method==PUT)
        return find_target_node_breadth_traversal(root,target) ;
}

BST *insert_node(BST *root, BST *new_node , int method)
{
    if(root==NULL)
        return new_node ;
    else
    {
        BST *target = find_target_node_traversal(root,new_node->value,method) ;
        if(target==NULL)
            return root ;
        else if(target->value == new_node->value)
        {
            if(method==SEEK)
                printf("Duplication found!\n") ;
            else if(method==PUT)
                target->value = new_node->value ;
        }
        else if(target->value > new_node->value)
        {
            if(target->adjacent[LEFT]==NULL)
                target->adjacent[LEFT] = new_node ;
            else
                insert_node(target->adjacent[LEFT],new_node,method) ;
        }
        else if(target->value < new_node->value)
        {
            if(target->adjacent[RIGHT]==NULL)
                target->adjacent[RIGHT] = new_node ;
            else
                insert_node(target->adjacent[RIGHT],new_node,method) ;
        }
        new_node->parent  = target ;
        return root ;
    }
}

void display_inorder_using_stack(BST *root)
{
    if(root == NULL)
        return ;
    BST *stack[1000], *temp ;
    int top = -1 ;
    temp = root ;
    while(1)
    {
        while(temp != NULL)
        {
            stack[++top] = temp ;
            temp = temp->adjacent[LEFT] ;
        }
        if(top == -1)
            break ;
        temp = stack[top--] ;
        printf("%d ",temp->value) ;
        temp = temp->adjacent[RIGHT] ;
    }
}

void display_inorder_recursive(BST *root)
{
    if(root==NULL)
        return ;
    display_inorder_recursive(root->adjacent[LEFT]) ;
    printf("%d ",root->value) ;
    display_inorder_recursive(root->adjacent[RIGHT]) ;
}

void display_inorder(BST *root, int method)
{
    if(method==SEEK)
        display_inorder_recursive(root) ;
    else if(method==PUT)
        display_inorder_using_stack(root) ;
}

void delete_node(BST *root, int target, int method)
{
    BST *target_node = find_target_node_traversal(root,target,method) ;
    if(target_node==NULL)
    {
        if(method==SEEK)
            printf("Target node not found!\n") ;
        else if(method==PUT)
            return ;
    }
    else
    {
        BST* temp ;
        if(target_node->adjacent[LEFT]==NULL && target_node->adjacent[RIGHT]==NULL)
        {
            if(target_node->parent->adjacent[LEFT]==target_node)
                target_node->parent->adjacent[LEFT]=NULL ;
            else if(target_node->parent->adjacent[RIGHT]==target_node)
                target_node->parent->adjacent[RIGHT]=NULL ;
            free(target_node) ;
        }
        else if(target_node->adjacent[LEFT]==NULL || target_node->adjacent[RIGHT]==NULL)
        {
            if(target_node->adjacent[LEFT]!=NULL)
                temp = target_node->adjacent[LEFT] ;
            else if(target_node->adjacent[RIGHT]!=NULL)
                temp = target_node->adjacent[RIGHT] ;
            if(target_node->parent->adjacent[LEFT]==target_node)
                target_node->parent->adjacent[LEFT]=temp ;
            else if(target_node->parent->adjacent[RIGHT]==target_node)
                target_node->parent->adjacent[RIGHT]=temp ;
            free(target_node) ;
        }
        else
        {
            BST* successor = target_node->adjacent[RIGHT] ;
            while(successor->adjacent[LEFT]!=NULL)
                successor = successor->adjacent[LEFT] ;
            delete_node(root,successor->value,PUT) ;
            target_node->value = successor->value ;
        }
    }
}

int main()
{
    BST *root = NULL ;
    int choice, target, method ;
    while(1)
    {
        scanf("%d",&choice) ;
        switch(choice)
        {
            case 1: scanf("%d",&target) ; insert_node(root,new_BST_node(target),PUT) ; break ;
            case 2: scanf("%d %d",&target,&method) ; delete_node(root,target,method) ; break ;
            case 3: scanf("%d",&method) ; display_inorder(root,method) ; printf("\n") ; break ;
            case 4: break ;
        }
        if(choice==4)
            break ;
    }
    return 0 ;
}