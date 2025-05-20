//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

struct listNode
{
    int data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, int number);
int delete( ListNodePtr *sPtr, int number );
int search(ListNodePtr sPtr, int number );
void printList( ListNodePtr currentPtr );
void instructions( void );

int main()
{
    ListNodePtr startPtr = NULL;
    int choice;
    int num;

    instructions();
    scanf( "%d", &choice );

    while( choice != 5 )
    {
        switch( choice )
        {
            case 1:
                printf( "Enter a number: " );
                scanf( "%d", &num );
                insert( &startPtr, num );
                printList( startPtr );
                break;
            case 2:
                if( startPtr != NULL )
                {
                    printf( "Enter a number to delete: " );
                    scanf( "%d", &num );

                    if( delete( &startPtr, num ) )
                    {
                        printf( "Deleted %d.\n", num );
                        printList( startPtr );
                    }
                    else
                    {
                        printf( "%d not found.\n\n", num );
                    }
                }
                else
                {
                    printf( "List is empty.\n\n" );
                }
                break;
            case 3:
                if( startPtr != NULL )
                {
                    printf( "Enter a number to search: " );
                    scanf( "%d", &num );
                    if( search( startPtr, num ) )
                    {
                        printf( "%d is found in the list\n", num );
                    }
                    else
                    {
                        printf( "%d is not in the list.\n", num );
                    }
                }
                else
                {
                    printf( "List is empty.\n\n" );
                }
                break;
            case 4:
                if( startPtr != NULL )
                {
                    printList( startPtr );
                }
                else
                {
                    printf( "List is empty.\n\n" );
                }
                break;
            default:
                printf( "Invalid choice.\n\n" );
                instructions();
                break;
        }
        scanf( "%d", &choice );
    }
    printf( "End of run.\n" );
    return 0;
}

void instructions( void )
{
    printf( "Enter your choice:\n 1 to insert an element into the list.\n 2 to delete an element from the list.\n 3 to search for an element in the list.\n 4 to print the list.\n 5 to quit.\n" );
}

void insert( ListNodePtr *sPtr, int number )
{
    ListNodePtr newPtr = malloc( sizeof(ListNode) );
    if( newPtr != NULL )
    {
        newPtr->data = number;
        newPtr->nextPtr = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        while( currentPtr != NULL && number > currentPtr->data )
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if( previousPtr == NULL )
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf( "Not inserted. No memory available.\n" );
    }
}

int delete( ListNodePtr *sPtr, int number )
{
    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *sPtr;

    while( currentPtr != NULL && number != currentPtr->data )
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if( currentPtr != NULL )
    {
        if( previousPtr == NULL )
        {
            *sPtr = currentPtr->nextPtr;
        }
        else
        {
            previousPtr->nextPtr = currentPtr->nextPtr;
        }
        free( currentPtr );
        return number;
    }
    else
    {
        return 0;
    }
}

int search(ListNodePtr sPtr, int number )
{
    ListNodePtr currentPtr = sPtr;
    while( currentPtr != NULL )
    {
        if( currentPtr->data == number )
        {
            return 1;
        }
        currentPtr = currentPtr->nextPtr;
    }
    return 0;
}

void printList( ListNodePtr currentPtr )
{
    if( currentPtr == NULL )
    {
        printf( "List is empty.\n\n" );
    }
    else
    {
        printf( "The list is:\n" );
        while( currentPtr != NULL )
        {
            printf( "%d --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        }
        printf( "NULL\n\n" );
    }
}