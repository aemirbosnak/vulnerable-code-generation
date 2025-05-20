//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

// structure for memory block allocation
struct memory_block {
    int start;
    int end;
    int size;
};

// array of memory blocks initially empty
struct memory_block mem[10000]; 

// function to add a memory block
void add_memory_block(int start, int end, int size) {
    int i;
    for(i=0; i<10000; i++) {
        if(mem[i].size==0) {
            mem[i].start = start;
            mem[i].end = end;
            mem[i].size = size;
            printf("Memory block allocated from %d to %d of size %d bytes\n", start, end, size);
            break;
        }
    }
}

// function to remove a memory block
void remove_memory_block(int start, int end) {
    int i;
    for(i=0; i<10000; i++) {
        if(mem[i].start==start && mem[i].end==end) {
            mem[i].start = 0;
            mem[i].end = 0;
            mem[i].size = 0;
            printf("Memory block deallocated from %d to %d\n", start, end);
            break;
        }
    }
}

int main() {
    int choice, start, end, size;
    
    do {
        printf("\n1. Add a memory block\n");
        printf("2. Remove a memory block\n");
        printf("3. View memory blocks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter starting address of memory block: ");
                scanf("%d", &start);
                printf("Enter ending address of memory block: ");
                scanf("%d", &end);
                size = end-start+1;
                add_memory_block(start, end, size);
                break;
                
            case 2:
                printf("\nEnter starting address of memory block to deallocate: ");
                scanf("%d", &start);
                printf("Enter ending address of memory block to deallocate: ");
                scanf("%d", &end);
                remove_memory_block(start, end);
                break;
                
            case 3:
                printf("\nMemory blocks:\n");
                for(int i=0; i<10000; i++) {
                    if(mem[i].size != 0) {
                        printf("From %d to %d of size %d bytes\n", mem[i].start, mem[i].end, mem[i].size);
                    }
                }
                break;
                
            case 4:
                printf("\nExiting program...\n");
                break;
                
            default:
                printf("\nInvalid choice.\n");
                break;
        }
        
    } while(choice!=4);
    
    return 0;
}