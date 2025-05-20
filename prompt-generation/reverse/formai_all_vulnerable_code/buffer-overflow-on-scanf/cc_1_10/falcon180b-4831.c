//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define PI 3.14159265358979323846

typedef struct {
    float value;
    int type;
} component;

component create_resistor(float value) {
    component res;
    res.value = value;
    res.type = 1;
    return res;
}

component create_capacitor(float value) {
    component cap;
    cap.value = value;
    cap.type = 2;
    return cap;
}

component create_inductor(float value) {
    component ind;
    ind.value = value;
    ind.type = 3;
    return ind;
}

void print_component(component c) {
    if(c.type == 1)
        printf("Resistor: %f\n",c.value);
    else if(c.type == 2)
        printf("Capacitor: %f\n",c.value);
    else
        printf("Inductor: %f\n",c.value);
}

int main() {
    int n,i,j;
    float f;
    char s[100];
    component *circuit;

    printf("Enter the number of components: ");
    scanf("%d",&n);

    circuit = (component*) malloc(n * sizeof(component));

    for(i=0; i<n; i++) {
        printf("Enter the type of component (R for resistor, C for capacitor, L for inductor): ");
        scanf("%s",s);

        switch(s[0]) {
            case 'R':
                printf("Enter the value of resistor: ");
                scanf("%f",&f);
                circuit[i] = create_resistor(f);
                break;
            case 'C':
                printf("Enter the value of capacitor: ");
                scanf("%f",&f);
                circuit[i] = create_capacitor(f);
                break;
            case 'L':
                printf("Enter the value of inductor: ");
                scanf("%f",&f);
                circuit[i] = create_inductor(f);
                break;
            default:
                printf("Invalid input!\n");
                exit(0);
        }
    }

    printf("Circuit components:\n");
    for(i=0; i<n; i++) {
        print_component(circuit[i]);
    }

    free(circuit);
    return 0;
}