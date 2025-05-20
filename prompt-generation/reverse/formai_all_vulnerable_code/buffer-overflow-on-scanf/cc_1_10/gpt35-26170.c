//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include<stdio.h>
#include<math.h>

#define MAX_NODES 100
#define MAX_VALUE 1000000.00

struct element {
    int node1,node2;
    double value;
    char type;
};

struct element circuit[MAX_NODES];
double nodeVoltage[MAX_NODES];

void solve(int n) {
    for(int i=1;i<=n;i++) {
        nodeVoltage[i]=MAX_VALUE;
    }

    for(int i=0;i<1;i++) {
        for(int j=0;j<n;j++) {
            if(nodeVoltage[circuit[j].node1]==MAX_VALUE && nodeVoltage[circuit[j].node2]==MAX_VALUE) {
                continue;
            }
            if(nodeVoltage[circuit[j].node1]!=MAX_VALUE && nodeVoltage[circuit[j].node2]!=MAX_VALUE) {
                continue;
            }

            if(circuit[j].type=='R') {
                if(nodeVoltage[circuit[j].node1]==MAX_VALUE) {
                    nodeVoltage[circuit[j].node1]=nodeVoltage[circuit[j].node2]-circuit[j].value;
                } else {
                    nodeVoltage[circuit[j].node2]=nodeVoltage[circuit[j].node1]+circuit[j].value;
                }
            }
            if(circuit[j].type=='C') {
                if(nodeVoltage[circuit[j].node1]==MAX_VALUE) {
                    nodeVoltage[circuit[j].node1]=nodeVoltage[circuit[j].node2]-circuit[j].value*nodeVoltage[0];
                } else {
                    nodeVoltage[circuit[j].node2]=nodeVoltage[circuit[j].node1]+circuit[j].value*nodeVoltage[0];
                }
            }
            if(circuit[j].type=='L') {
                if(nodeVoltage[circuit[j].node1]==MAX_VALUE) {
                    nodeVoltage[circuit[j].node1]=nodeVoltage[circuit[j].node2]+circuit[j].value*nodeVoltage[0];
                } else {
                    nodeVoltage[circuit[j].node2]=nodeVoltage[circuit[j].node1]-circuit[j].value*nodeVoltage[0];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the circuit: ");
    scanf("%d",&n);

    printf("Enter the circuit elements...\n");
    for(int i=0;i<n;i++) {
        printf("Enter element %d in format (node1 node2 value type): ",i+1);
        scanf("%d %d %lf %c",&circuit[i].node1,&circuit[i].node2,&circuit[i].value,&circuit[i].type);
    }

    solve(n);

    printf("The voltages at each node are...\n");
    for(int i=1;i<=n;i++) {
        printf("Node %d: %.2lf\n",i,nodeVoltage[i]);
    }

    return 0;
}