//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Define the structure for an appointment
    typedef struct {
        char *name;
        char *email;
        int time;
        int duration;
    } Appointment;

    // Define the structure for a linked list node
    typedef struct Node {
        Appointment appointment;
        struct Node *next;
    } Node;

    // Define the structure for a linked list
    typedef struct {
        Node *head;
        Node *tail;
    } List;

    // Initialize the linked list
    void init_list(List *list) {
        list->head = NULL;
        list->tail = NULL;
    }

    // Add a new appointment to the linked list
    void add_appointment(List *list, Appointment appointment) {
        Node *node = malloc(sizeof(Node));
        node->appointment = appointment;
        node->next = NULL;

        if (list->head == NULL) {
            list->head = node;
        } else {
            list->tail->next = node;
        }

        list->tail = node;
    }

    // Get the number of appointments in the linked list
    int get_appointment_count(List *list) {
        int count = 0;
        Node *node = list->head;
        while (node != NULL) {
            count++;
            node = node->next;
        }
        return count;
    }

    // Find an appointment by name
    Appointment *find_appointment(List *list, char *name) {
        Node *node = list->head;
        while (node != NULL) {
            if (strcmp(node->appointment.name, name) == 0) {
                return &node->appointment;
            }
            node = node->next;
        }
        return NULL;
    }

    // Delete an appointment by name
    void delete_appointment(List *list, char *name) {
        Node *node = list->head;
        Node *prev = NULL;
        while (node != NULL) {
            if (strcmp(node->appointment.name, name) == 0) {
                if (prev == NULL) {
                    list->head = node->next;
                } else {
                    prev->next = node->next;
                }
                if (node == list->tail) {
                    list->tail = prev;
                }
                free(node);
                return;
            }
            prev = node;
            node = node->next;
        }
    }

    // Display all appointments in the linked list
    void display_appointments(List *list) {
        Node *node = list->head;
        while (node != NULL) {
            printf("%s %s %d %d\n", node->appointment.name, node->appointment.email, node->appointment.time, node->appointment.duration);
            node = node->next;
        }
    }

    int main() {
        List list;
        init_list(&list);

        add_appointment(&list, (Appointment){"John", "john@example.com", 1000, 60});
        add_appointment(&list, (Appointment){"Jane", "jane@example.com", 1060, 30});
        add_appointment(&list, (Appointment){"Bob", "bob@example.com", 1120, 60});

        Appointment *appointment = find_appointment(&list, "John");
        printf("Appointment: %s %s %d %d\n", appointment->name, appointment->email, appointment->time, appointment->duration);

        delete_appointment(&list, "Jane");

        display_appointments(&list);

        return 0;
    }