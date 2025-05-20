//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

struct location {
    double lat;
    double lon;
}current = {0.0, 0.0};

struct node {
    struct location loc;
    struct node *next;
}*head = NULL, *tail = NULL;

void add_node(double lat, double lon) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->loc.lat = lat;
    new_node->loc.lon = lon;
    new_node->next = NULL;
    if(head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void display_path() {
    struct node *temp = head;
    printf("GPS Navigation Path:\n");
    while(temp != NULL) {
        printf("%lf %lf\n", temp->loc.lat, temp->loc.lon);
        temp = temp->next;
    }
}

int main() {
    char choice;
    do {
        double lat, lon;
        printf("Enter the current latitude and longitude: ");
        scanf("%lf %lf", &current.lat, &current.lon);
        printf("Add the location to the navigation path? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'y' || choice == 'Y') {
            add_node(current.lat, current.lon);
        }
        printf("Continue navigation? (y/n): ");
        scanf(" %c", &choice);
        system("clear");
    } while(choice == 'y' || choice == 'Y');

    display_path();
    return 0;
}