//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include<stdio.h>
#include<string.h>

#define MAX_SLOTS 10
#define MAX_BAGGAGE 25

char slots[MAX_SLOTS][5]; // array to hold the slots
char baggage[MAX_BAGGAGE][5]; // array to hold the baggage 
int top = -1; // counter for baggage array
int available_slots = MAX_SLOTS; // variable for available slots
int used_slots = 0; // variable for used slots

// function to check if a slot is available
int is_slot_available(){
    if(available_slots > 0){
        return 1;
    }else{
        return 0;
    }
}

// function to get next available slot
int get_next_slot(){
    for(int i=0; i<MAX_SLOTS; i++){
        if(strcmp(slots[i], "") == 0){
            return i;
        }
    }
    return -1;
}

// function to add a baggage to a slot
void add_to_slot(int slot_num, char* bag_id){
    strcpy(slots[slot_num], bag_id);
    used_slots++;
    available_slots--;
}

// function to remove a baggage from a slot
void remove_from_slot(int slot_num){
    strcpy(slots[slot_num], "");
    used_slots--;
    available_slots++;
}

// main function
int main(){

    char choice;

    while(1){
        printf("Enter 1 to add a baggage, 2 to remove a baggage, 3 to view all baggages, or q to quit: ");
        scanf(" %c", &choice);

        switch(choice){
            case '1':
            {
                if(is_slot_available()){
                    char bag_id[5];
                    printf("Enter baggage ID (4 characters max): ");
                    scanf(" %[^\n]s", bag_id);
                    top++;
                    strcpy(baggage[top], bag_id);
                    int slot_num = get_next_slot();
                    add_to_slot(slot_num, baggage[top]);
                    printf("Baggage added to slot %d\n", slot_num+1);
                }else{
                    printf("No slots available. Please remove a baggage first.\n");
                }
                break;
            }
            case '2':
            {
                if(used_slots > 0){
                    int slot_num;
                    printf("Enter slot number to remove baggage from (1-%d): ", MAX_SLOTS);
                    scanf("%d", &slot_num);
                    if(slot_num > 0 && slot_num <= MAX_SLOTS){
                        remove_from_slot(slot_num-1);
                        printf("Baggage removed from slot %d\n", slot_num);
                    }else{
                        printf("Invalid slot number.\n");
                    }
                }else{
                    printf("No baggages available. Please add a baggage first.\n");
                }
                break;
            }
            case '3':
            {
                printf("Slots:\n");
                for(int i=0; i<MAX_SLOTS; i++){
                    printf("%d: %s\n", i+1, slots[i]);
                }
                printf("Baggages:\n");
                for(int i=0; i<=top; i++){
                    printf("%d: %s\n", i+1, baggage[i]);
                }
                break;
            }
            case 'q':
            {
                printf("Exiting...\n");
                return 0;
            }
            default:
            {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}