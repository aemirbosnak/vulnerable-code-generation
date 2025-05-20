//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    char name[30];
    int pin1;
    int pin2;
    int value;
    int state;
}component;

typedef struct{
    int num_components;
    component *components;
}circuit;

void create_circuit(circuit *c){
    c->num_components=0;
    c->components=NULL;
}

void add_component(circuit *c, char *name, int pin1, int pin2, int value, int state){
    component *new_component=malloc(sizeof(component));
    strcpy(new_component->name, name);
    new_component->pin1=pin1;
    new_component->pin2=pin2;
    new_component->value=value;
    new_component->state=state;
    c->components=realloc(c->components, sizeof(component)*(c->num_components+1));
    c->components[c->num_components]=*new_component;
    c->num_components++;
}

void simulate_circuit(circuit *c){
    int i, j;
    for(i=0; i<c->num_components; i++){
        for(j=0; j<c->num_components; j++){
            if(i!=j && c->components[i].pin1==c->components[j].pin2){
                c->components[i].state=c->components[j].state;
            }
        }
    }
}

void print_circuit(circuit *c){
    int i;
    for(i=0; i<c->num_components; i++){
        printf("%s %d %d %d %d\n", c->components[i].name, c->components[i].pin1, c->components[i].pin2, c->components[i].value, c->components[i].state);
    }
}

int main(){
    circuit c;
    create_circuit(&c);
    add_component(&c, "resistor", 1, 2, 100, 0);
    add_component(&c, "led", 2, 0, 0, 0);
    simulate_circuit(&c);
    print_circuit(&c);
    return 0;
}