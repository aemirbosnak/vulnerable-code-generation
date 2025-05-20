//FormAI DATASET v1.0 Category: Memory management ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int *ptr;
    int i, size, min_element, max_element, allocated_size;
    
    
    printf("How many elements do you want to allocate? ");
    scanf("%d", &size);
    
    ptr = (int*) malloc(size * sizeof(int));
    
    printf("\n-----Memory Allocation Complete-----\n");
    
    printf("\nNow, let's randomly assign some numbers to this memory block:\n");
    
    for (i=0; i<size; i++){
        ptr[i] = rand();
    }
    
    printf("\n-----Numbers assigned successfully-----\n");
    
    printf("\nWould you like to print the numbers? (1 = Yes | 0 = No) ");
    int print_choice;
    scanf("%d", &print_choice);
    
    if (print_choice == 1){
        printf("\nPrint All = 0\nPrint Range = 1\n");
        int print_type_choice;
        scanf("%d", &print_type_choice);
        
        if (print_type_choice == 0){
            printf("\nPrinting all numbers:\n");
            
            for (i=0; i<size; i++){
                printf("%d\t", ptr[i]);
            }
        }
        else if (print_type_choice == 1){
            printf("\nEnter the range of numbers you want to print: \n");
            printf("Minimum element: ");
            scanf("%d", &min_element);
            printf("Maximum element: ");
            scanf("%d", &max_element);
            
            if (max_element < min_element){
                printf("\nInvalid Range!");
                return 0;
            }
            
            printf("\nPrinting numbers in given range [%d, %d]: \n", min_element, max_element);
            
            for (i=0; i<size; i++){
                if (ptr[i] >= min_element && ptr[i] <= max_element){
                    printf("%d\t", ptr[i]);
                }
            }
        }
        else{
            printf("\nInvalid Choice!");
            return 0;
        }
    }
    
    printf("\n-----Memory Usage Statistics-----\n");
    
    allocated_size = size * sizeof(int);
    
    printf("\nMemory Allocated: %d bytes", allocated_size);
    
    
    int deleted_value;
    
    printf("\n\n-----Cleaning Up Memory-----\n");
    
    printf("\nWhich element do you want to delete? (Enter the index number)\nIndex = ");
    scanf("%d", &i);
    
    if (i < 0 || i>=size){
        printf("\nInvalid Index!");
        return 0;
    }
    
    deleted_value = ptr[i];
    printf("\nDeleted Element: %d\n", deleted_value);
    
    for (; i<size-1; i++){
        ptr[i] = ptr[i+1];
    }
    
    size -= 1;
    ptr = (int*) realloc(ptr, size * sizeof(int));
    
    printf("\n-----Memory Cleanup Complete-----\n");
    
    printf("\nRemaining Memory:\n");
    
    for (i=0; i<size; i++){
        printf("%d\t", ptr[i]);
    }
    
    allocated_size = size * sizeof(int);
    printf("\n\nMemory Allocated: %d bytes\n", allocated_size);
    
    printf("\nGoodbye!");
    
    free(ptr);
    
    return 0;
}