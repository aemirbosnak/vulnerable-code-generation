//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HEAP_SIZE 1000 // size of the heap
#define BLOCK_SIZE 16 // size of each block
typedef struct block{
    size_t size; // size of the block
    int free; // flag indicating whether this block is available or not
    struct block *next; // pointer to the next block
}Block;
Block *freeList = (void*)0; // initialize free list to NULL
char heap[HEAP_SIZE]; // our heap

// Function to initialize our heap
void init(){
    freeList = (Block*)heap; // point to the start of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

// Function to malloc memory from our heap
void *myMalloc(size_t num){
    Block *temp = freeList;
    while(temp!= NULL){
        if(temp->size == num){
            temp->free = 0;
            return (void*)(++temp);
        }
        temp = temp->next;
    }
    if(freeList->size >= num){
        freeList->size -= num;
        freeList->free = 0;
        return (void*)(++freeList);
    }
    printf("Out of memory\n");
    return NULL;
}

// Function to free memory back to our heap
void myFree(void *ptr){
    if(ptr == NULL)
        return;
    if(ptr <= heap || ptr >= heap + HEAP_SIZE)
        return;
    Block *temp = (Block*)ptr;
    --temp;
    temp->free = 1;
}

// Function to print the current state of our heap
void printHeap(){
    Block *temp = freeList;
    printf("Heap:\n");
    while(temp!= NULL){
        printf("%p - %p : %d\n", temp, temp->next, temp->size);
        temp = temp->next;
    }
}

int main(){
    init();
    int i;
    for(i=0;i<10;i++){
        char *ptr = myMalloc(i*BLOCK_SIZE);
        memset(ptr, i, i*BLOCK_SIZE);
    }
    printHeap();
    for(i=0;i<5;i++){
        myFree(myMalloc(i*BLOCK_SIZE));
    }
    printHeap();
    return 0;
}