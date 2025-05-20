//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define MAX_MEDICINES 1000
#define MAX_NAME_LENGTH 25
#define MAX_COMPANY_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_NAME_LENGTH];
    int quantity;
    double price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

pthread_mutex_t mutex;

void addMedicine() {
    pthread_mutex_lock(&mutex);
    printf("Adding medicine...\n");
    Medicine newMedicine;
    newMedicine.id = numMedicines + 1;
    printf("Enter name: ");
    scanf("%s", newMedicine.name);
    printf("Enter company: ");
    scanf("%s", newMedicine.company);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%lf", &newMedicine.price);
    medicines[numMedicines++] = newMedicine;
    printf("Medicine added successfully!\n");
    pthread_mutex_unlock(&mutex);
}

void viewMedicines() {
    pthread_mutex_lock(&mutex);
    printf("List of medicines:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("ID: %d\n", medicines[i].id);
        printf("Name: %s\n", medicines[i].name);
        printf("Company: %s\n", medicines[i].company);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Price: %.2lf\n", medicines[i].price);
        printf("\n");
    }
    pthread_mutex_unlock(&mutex);
}

void *menu(void *threadid) {
    long tid;
    tid = (long) threadid;
    int option;
    while (1) {
        printf("Thread %ld: Menu\n", tid);
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                pthread_exit(NULL);
            default:
                printf("Invalid option!\n");
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    pthread_mutex_init(&mutex, NULL);
    for (t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, menu, (void *) t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}