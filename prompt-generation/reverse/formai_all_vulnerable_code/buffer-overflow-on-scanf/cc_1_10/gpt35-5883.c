//FormAI DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    printf("Welcome to the Memory Management Castle\n"); 
    printf("We have limited memory resources like Soldiers in a battle\n");
    printf("The King has set aside a specific number of Soldiers that can be used for battle\n");
    printf("You will have to strategize and allocate Soldiers to different Warlords efficiently\n\n");

    int total_soldiers = 1000;  // Total number of available Soldiers
    int* allocated_soldiers = malloc(0);  // Stores allocated Soldiers by Warlords
    int num_warlords = 0;  // Number of Warlords in battle

    while (total_soldiers > 0) {
        char choice;
        printf("Enter 1 to create a new Warlord and 2 to allocate Soldiers to existing Warlords: ");
        scanf("%c", &choice);
        
        switch (choice) {
            case '1': 
                printf("Enter the number of Soldiers to be allocated for the new Warlord: ");
                int new_soldiers;
                scanf("%d", &new_soldiers);
                if (new_soldiers > total_soldiers) {
                    printf("Error: Not enough Soldiers available for allocation\n");
                } else {
                    allocated_soldiers = realloc(allocated_soldiers, (num_warlords+1)*sizeof(int));
                    allocated_soldiers[num_warlords] = new_soldiers;
                    printf("New Warlord created with %d Soldiers\n", new_soldiers);
                    num_warlords += 1;
                    total_soldiers -= new_soldiers;
                }
                break;
            case '2':
                printf("Select Warlord to allocate Soldiers to (1-%d): ", num_warlords);
                int warlord_choice;
                scanf("%d", &warlord_choice);
                if (warlord_choice > num_warlords) {
                    printf("Error: Invalid Warlord selection\n");
                } else {
                    printf("Enter the number of Soldiers to be allocated to Warlord %d: ", warlord_choice);
                    int existing_soldiers;
                    scanf("%d", &existing_soldiers);
                    if (existing_soldiers > total_soldiers) {
                        printf("Error: Not enough Soldiers available for allocation\n");
                    } else {
                        allocated_soldiers[warlord_choice-1] += existing_soldiers;
                        total_soldiers -= existing_soldiers;
                        printf("%d Soldiers successfully allocated to Warlord %d\n", existing_soldiers, warlord_choice);
                    }
                }
                break;
            default:
                printf("Error: Invalid input\n");
                break;
        }

        printf("\nTotal number of Soldiers remaining: %d\n\n", total_soldiers);
        getchar();  // Clear input buffer
    }

    printf("All Soldiers have been allocated!\n");
    printf("Warlord's Soldiers allocation summary:\n");
    for (int i=0; i<num_warlords; i++) {
        printf("Warlord %d: %d Soldiers\n", i+1, allocated_soldiers[i]);
    }

    free(allocated_soldiers);

    return 0; 
}