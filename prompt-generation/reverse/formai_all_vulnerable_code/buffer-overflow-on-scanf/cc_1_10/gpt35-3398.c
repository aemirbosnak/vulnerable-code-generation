//FormAI DATASET v1.0 Category: Bitwise operations ; Style: secure
#include<stdio.h> 
  
/* Function to set the bit of a given number n at specified position */
int set_bit(int n, int pos) 
{ 
    return ((n | (1 << pos))); 
} 
  
/* Function to clear the bit of a given number n at specified position */
int clear_bit(int n, int pos) 
{ 
    return (n & (~(1 << pos))); 
} 
  
/* Function to check if the bit of a given number n at specified position is set or not */
int is_bit_set(int n, int pos) 
{ 
    return ((n & (1 << pos)) != 0); 
} 
  
int main() 
{ 
    int n, pos, choice; 
    printf("Enter the number: "); 
    scanf("%d",&n); 
    printf("Enter the bit position to be changed: "); 
    scanf("%d",&pos); 
    printf("Enter the operation to be performed:\n"); 
    printf("1. Set bit\n"); 
    printf("2. Clear bit\n"); 
    printf("3. Check if bit is set\n"); 
    scanf("%d",&choice); 
    switch(choice) 
    { 
        case 1:
            printf("New number after setting bit is %d\n",set_bit(n, pos));
            break;
        case 2:
            printf("New number after clearing bit is %d\n",clear_bit(n, pos));
            break;
        case 3:
            if(is_bit_set(n, pos))
                printf("%dth bit is set in the number %d\n",pos, n);
            else
                printf("%dth bit is not set in the number %d\n",pos, n);
            break;
        default:
            printf("Invalid choice\n");
    } 
    return 0; 
}