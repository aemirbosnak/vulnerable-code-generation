//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define circuit component structures */
struct Resistor {
    double resistance;
};

struct Capacitor {
    double capacitance;
    double voltage;
};

struct Inductor {
    double inductance;
    double current;
};

struct VoltageSource {
    double voltage;
};

struct CurrentSource {
    double current;
};

/* Define circuit node structure */
struct Node {
    struct Resistor *r;
    struct Capacitor *c;
    struct Inductor *l;
    struct VoltageSource *v;
    struct CurrentSource *i;
    struct Node *next;
};

/* Define global variables */
struct Node *head = NULL;
int num_nodes = 0;
double start_time = 0.0;
double end_time = 0.0;
double time_step = 0.0;

/* Function prototypes */
void add_resistor(double resistance);
void add_capacitor(double capacitance, double voltage);
void add_inductor(double inductance, double current);
void add_voltage_source(double voltage);
void add_current_source(double current);
void simulate_circuit();
void print_results();

/* Main function */
int main() {
    printf("*** Welcome to the C Classical Circuit Simulator! ***\n");

    /* Get circuit input */
    int choice = 0;
    do {
        printf("Please choose a component to add to the circuit:\n");
        printf("1. Resistor\n");
        printf("2. Capacitor\n");
        printf("3. Inductor\n");
        printf("4. Voltage source\n");
        printf("5. Current source\n");
        printf("6. Simulate circuit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        /* Add component to circuit */
        switch (choice) {
            case 1:
                printf("Enter resistor resistance (ohms): ");
                double resistance;
                scanf("%lf", &resistance);
                add_resistor(resistance);
                break;
            case 2:
                printf("Enter capacitor capacitance (farads): ");
                double capacitance;
                scanf("%lf", &capacitance);
                printf("Enter initial capacitor voltage (volts): ");
                double voltage;
                scanf("%lf", &voltage);
                add_capacitor(capacitance, voltage);
                break;
            case 3:
                printf("Enter inductor inductance (henrys): ");
                double inductance;
                scanf("%lf", &inductance);
                printf("Enter initial inductor current (amps): ");
                double current;
                scanf("%lf", &current);
                add_inductor(inductance, current);
                break;
            case 4:
                printf("Enter voltage source voltage (volts): ");
                double v_voltage;
                scanf("%lf", &v_voltage);
                add_voltage_source(v_voltage);
                break;
            case 5:
                printf("Enter current source current (amps): ");
                double i_current;
                scanf("%lf", &i_current);
                add_current_source(i_current);
                break;
            case 6:
                printf("Enter simulation start time (seconds): ");
                scanf("%lf", &start_time);
                printf("Enter simulation end time (seconds): ");
                scanf("%lf", &end_time);
                printf("Enter simulation time step (seconds): ");
                scanf("%lf", &time_step);
                simulate_circuit();
                print_results();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

/* Add resistor to circuit */
void add_resistor(double resistance) {
    /* Create new node */
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->r = (struct Resistor*) malloc(sizeof(struct Resistor));
    new_node->r->resistance = resistance;
    new_node->c = NULL;
    new_node->l = NULL;
    new_node->v = NULL;
    new_node->i = NULL;
    new_node->next = head;
    head = new_node;
    num_nodes++;
}

/* Add capacitor to circuit */
void add_capacitor(double capacitance, double voltage) {
    /* Create new node */
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->r = NULL;
    new_node->c = (struct Capacitor*) malloc(sizeof(struct Capacitor));
    new_node->c->capacitance = capacitance;
    new_node->c->voltage = voltage;
    new_node->l = NULL;
    new_node->v = NULL;
    new_node->i = NULL;
    new_node->next = head;
    head = new_node;
    num_nodes++;
}

/* Add inductor to circuit */
void add_inductor(double inductance, double current) {
    /* Create new node */
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->r = NULL;
    new_node->c = NULL;
    new_node->l = (struct Inductor*) malloc(sizeof(struct Inductor));
    new_node->l->inductance = inductance;
    new_node->l->current = current;
    new_node->v = NULL;
    new_node->i = NULL;
    new_node->next = head;
    head = new_node;
    num_nodes++;
}

/* Add voltage source to circuit */
void add_voltage_source(double voltage) {
    /* Create new node */
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->r = NULL;
    new_node->c = NULL;
    new_node->l = NULL;
    new_node->v = (struct VoltageSource*) malloc(sizeof(struct VoltageSource));
    new_node->v->voltage = voltage;
    new_node->i = NULL;
    new_node->next = head;
    head = new_node;
    num_nodes++;
}

/* Add current source to circuit */
void add_current_source(double current) {
    /* Create new node */
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->r = NULL;
    new_node->c = NULL;
    new_node->l = NULL;
    new_node->v = NULL;
    new_node->i = (struct CurrentSource*) malloc(sizeof(struct CurrentSource));
    new_node->i->current = current;
    new_node->next = head;
    head = new_node;
    num_nodes++;
}

/* Simulate circuit */
void simulate_circuit() {
    double current_time = start_time;

    while (current_time <= end_time) {
        /* Calculate new voltages and currents */
        struct Node *current_node = head;
        while (current_node != NULL) {
            if (current_node->v != NULL) {
                current_node->c->voltage = current_node->v->voltage;
            } else if (current_node->i != NULL) {
                current_node->l->current = current_node->i->current;
            } else if (current_node->r != NULL) {
                /* Calculate voltage across resistor */
                double voltage_diff = 0.0;
                if (current_node->next->c != NULL) {
                    /* Calculate voltage across resistor and capacitor */
                    voltage_diff = current_node->next->c->voltage - current_node->c->voltage;
                } else if (current_node->next->l != NULL) {
                    /* Calculate voltage across resistor and inductor */
                    voltage_diff = current_node->next->l->current - current_node->l->current;
                }
                /* Calculate current through resistor */
                double current = voltage_diff / current_node->r->resistance;
                /* Update current through resistor */
                current_node->i->current = current;
                /* Update voltage across capacitor or inductor */
                if (current_node->next->c != NULL) {
                    current_node->c->voltage += current * time_step / current_node->c->capacitance;
                } else if (current_node->next->l != NULL) {
                    current_node->l->current += voltage_diff * time_step / current_node->l->inductance;
                }
            }
            current_node = current_node->next;
        }

        /* Update current time */
        current_time += time_step;
    }
}

/* Print circuit simulation results */
void print_results() {
    printf("Time (s)\tNode Voltages (V)\tNode Currents (A)\n");
    struct Node *current_node = head;
    while (current_node != NULL) {
        if (current_node->v != NULL) {
            printf("%.2f\t%.2f\n", end_time, current_node->c->voltage);
        } else if (current_node->i != NULL) {
            printf("%.2f\t%.2f\n", end_time, current_node->l->current);
        } else {
            printf("%.2f\t%.2f\t%.2f\n", end_time, current_node->c->voltage, current_node->i->current);
        }
        current_node = current_node->next;
    }
}