//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include<stdio.h>

int main(){

    // Firewalls come in different shapes and sizes
    // Let's shape-shift our firewall program as per user requirements
    
    char shape;
    printf("What shape do you want the firewall program to take? (square/circle/triangle): ");
    scanf("%c", &shape);
    
    if(shape == 's' || shape == 'S'){
        // Code for square-shaped firewall program
        
        printf("+--------------------------+\n");
        printf("|                          |\n");
        printf("|                          |\n");
        printf("|                          |\n");
        printf("|                          |\n");
        printf("|                          |\n");
        printf("|                          |\n");
        printf("+--------------------------+\n");

    } else if(shape == 'c' || shape == 'C'){
        // Code for circle-shaped firewall program
        
        printf("       ****      \n");
        printf("     **    **        \n");
        printf("   **        **        \n");
        printf("  *            *      \n");
        printf(" *              *      \n");
        printf("*                *     \n");
        printf(" *              *      \n");
        printf("  *            *      \n");
        printf("   **        **        \n");
        printf("     **    **        \n");
        printf("       ****      \n");

    } else if(shape == 't' || shape == 'T'){
        // Code for triangle-shaped firewall program
        
        printf("            /\\\n");
        printf("           /  \\\n");
        printf("          /    \\\n");
        printf("         /      \\\n");
        printf("        /        \\\n");
        printf("       /          \\\n");
        printf("      /____________\\\n");
        
    } else {
        printf("Invalid shape entered!");
    }
    
    return 0;
}