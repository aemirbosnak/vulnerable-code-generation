//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_SERVICES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int status; // 0 for stopped, 1 for running
} Service;

void start_service(Service *service) {
    if (service->status == 1) {
        printf("Service %s is already running.\n", service->name);
    } else {
        service->status = 1;
        printf("Starting service %s...\n", service->name);
        // Simulated delay
        sleep(2);
        printf("Service %s started successfully.\n", service->name);
    }
}

void stop_service(Service *service) {
    if (service->status == 0) {
        printf("Service %s is already stopped.\n", service->name);
    } else {
        service->status = 0;
        printf("Stopping service %s...\n", service->name);
        // Simulated delay
        sleep(2);
        printf("Service %s stopped successfully.\n", service->name);
    }
}

void status_service(Service service) {
    if (service.status == 1) {
        printf("Service %s is running.\n", service.name);
    } else {
        printf("Service %s is stopped.\n", service.name);
    }
}

void list_services(Service services[], int count) {
    printf("\nService List:\n");
    for (int i = 0; i < count; i++) {
        printf("  - %s: %s\n", services[i].name, (services[i].status == 1) ? "Running" : "Stopped");
    }
}

int main() {
    Service services[MAX_SERVICES] = {
        {"Network", 0},
        {"Web Server", 0},
        {"Database", 0},
        {"SSH", 0},
        {"Email Service", 0},
        {"File Server", 0},
        {"DNS", 0},
        {"FTP", 0},
        {"Proxy Server", 0},
        {"Monitoring Service", 0}
    };

    int service_count = 10;
    int choice;
    char service_name[MAX_NAME_LENGTH];
    
    while (1) {
        printf("\nSystem Administration Menu:\n");
        printf("1. Start Service\n");
        printf("2. Stop Service\n");
        printf("3. Check Service Status\n");
        printf("4. List All Services\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter service name to start: ");
                scanf("%s", service_name);
                for (int i = 0; i < service_count; i++) {
                    if (strcmp(services[i].name, service_name) == 0) {
                        start_service(&services[i]);
                        break;
                    }
                }
                break;

            case 2:
                printf("Enter service name to stop: ");
                scanf("%s", service_name);
                for (int i = 0; i < service_count; i++) {
                    if (strcmp(services[i].name, service_name) == 0) {
                        stop_service(&services[i]);
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter service name to check status: ");
                scanf("%s", service_name);
                for (int i = 0; i < service_count; i++) {
                    if (strcmp(services[i].name, service_name) == 0) {
                        status_service(services[i]);
                        break;
                    }
                }
                break;

            case 4:
                list_services(services, service_count);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}