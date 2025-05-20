//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

typedef struct{
    char name[20];
    int val;
    float loc_x, loc_y;
    int (*ptr_fun)();
}component;

void add_component(component *c){
    printf("Enter component name: ");
    scanf("%s", c->name);
    printf("Enter component value: ");
    scanf("%d", &c->val);
    printf("Enter component location (x,y): ");
    scanf("%f %f", &c->loc_x, &c->loc_y);
    printf("Enter function pointer for component: ");
    scanf("%p", &c->ptr_fun);
}

int connect_components(component *c1, component *c2, float resist){
    float g = 1 / resist;
    c1->ptr_fun = &g;
    c2->ptr_fun = &g;
}

int main(){
    int n, i, j, m;
    float resist;
    component c[100];
    printf("Enter number of components: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        add_component(&c[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            printf("Do you want to connect %s and %s? (y/n): ", c[i].name, c[j].name);
            scanf(" %c", &m);
            if(m=='y' || m=='Y'){
                printf("Enter resistance of connection: ");
                scanf("%f", &resist);
                connect_components(&c[i], &c[j], resist);
            }
        }
    }
    for(i=0;i<n;i++){
        c[i].ptr_fun();
    }
    return 0;
}