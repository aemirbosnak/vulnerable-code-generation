//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 100
#define NAME_LENGTH 50

typedef struct {
    int ticket_id;
    char name[NAME_LENGTH];
    int is_available;
} Ticket;

Ticket tickets[MAX_TICKETS];
int ticket_count = 0;

void load_tickets() {
    FILE *file = fopen("tickets.txt", "r");
    if (file == NULL) {
        printf("Could not open tickets.txt for reading. A new file will be created.\n");
        return;
    }
    while (fscanf(file, "%d %s %d", &tickets[ticket_count].ticket_id, tickets[ticket_count].name, &tickets[ticket_count].is_available) != EOF) {
        ticket_count++;
    }
    fclose(file);
}

void save_tickets() {
    FILE *file = fopen("tickets.txt", "w");
    if (file == NULL) {
        printf("Could not open tickets.txt for writing.\n");
        return;
    }
    for (int i = 0; i < ticket_count; i++) {
        fprintf(file, "%d %s %d\n", tickets[i].ticket_id, tickets[i].name, tickets[i].is_available);
    }
    fclose(file);
}

void view_tickets() {
    printf("\nAvailable Tickets:\n");
    for (int i = 0; i < ticket_count; i++) {
        if (tickets[i].is_available) {
            printf("Ticket ID: %d | Name: %s | Status: Available\n",
                    tickets[i].ticket_id, tickets[i].name);
        }
    }
}

void book_ticket() {
    int ticket_id;
    printf("Enter the ticket ID you want to book: ");
    scanf("%d", &ticket_id);
    
    for (int i = 0; i < ticket_count; i++) {
        if (tickets[i].ticket_id == ticket_id && tickets[i].is_available) {
            tickets[i].is_available = 0;  // Mark ticket as booked
            printf("Ticket %d booked successfully!\n", ticket_id);
            save_tickets();
            return;
        }
    }
    printf("Ticket not found or already booked.\n");
}

void add_ticket() {
    if (ticket_count >= MAX_TICKETS) {
        printf("Cannot add more tickets. Maximum capacity reached.\n");
        return;
    }
    
    printf("Enter ticket ID: ");
    scanf("%d", &tickets[ticket_count].ticket_id);
    printf("Enter ticket name: ");
    scanf("%s", tickets[ticket_count].name);
    tickets[ticket_count].is_available = 1; // New ticket is available
    ticket_count++;
    save_tickets();
    printf("Ticket added successfully!\n");
}

void display_menu() {
    printf("\nTicket Booking System Menu:\n");
    printf("1. View Available Tickets\n");
    printf("2. Book a Ticket\n");
    printf("3. Add a New Ticket\n");
    printf("4. Exit\n");
}

int main() {
    load_tickets();
    int choice;

    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                view_tickets();
                break;
            case 2:
                book_ticket();
                break;
            case 3:
                add_ticket();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}