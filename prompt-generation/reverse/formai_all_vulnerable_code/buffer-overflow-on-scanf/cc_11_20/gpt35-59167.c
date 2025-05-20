//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXNODES 10
#define MAXELEMENTS 10

//structure to store information about elements
struct element
{
    char name[10];
    int node1,node2;
    float value;
};

//structure to store information about nodes
struct node
{
    int num;
    float voltage;
    int is_ground;
};

int main()
{
    int n_elements,n_nodes,i,j,k,index,ground_node=-1;
    float time,step,current;
    struct element elements[MAXELEMENTS];
    struct node nodes[MAXNODES];

    //take input from user
    printf("Enter the number of elements: ");
    scanf("%d",&n_elements);

    //take input for each element
    for(i=0;i<n_elements;i++)
    {
        printf("Enter the name of element %d: ",i+1);
        scanf("%s",elements[i].name);
        printf("Enter the value of %s: ",elements[i].name);
        scanf("%f",&elements[i].value);
        printf("Enter the node connections of %s: ",elements[i].name);
        scanf("%d %d",&elements[i].node1,&elements[i].node2);
    }

    //initialize nodes
    n_nodes=1;
    nodes[0].num=0;
    nodes[0].voltage=0;
    nodes[0].is_ground=1;

    //assign numbers to nodes
    for(i=0;i<n_elements;i++)
    {
        index=-1;
        for(j=0;j<n_nodes;j++)
        {
            if(elements[i].node1==nodes[j].num)
                index=j;
        }
        if(index==-1)
        {
            nodes[n_nodes].num=elements[i].node1;
            nodes[n_nodes].voltage=0;
            nodes[n_nodes].is_ground=0;
            if(nodes[n_nodes].num==0)
            {
                nodes[n_nodes].is_ground=1;
                ground_node=n_nodes;
            }
            n_nodes++;
        }

        index=-1;
        for(j=0;j<n_nodes;j++)
        {
            if(elements[i].node2==nodes[j].num)
                index=j;
        }
        if(index==-1)
        {
            nodes[n_nodes].num=elements[i].node2;
            nodes[n_nodes].voltage=0;
            nodes[n_nodes].is_ground=0;
            if(nodes[n_nodes].num==0)
            {
                nodes[n_nodes].is_ground=1;
                ground_node=n_nodes;
            }
            n_nodes++;
        }
    }

    //print node information
    printf("\nNode Information\n");
    for(i=0;i<n_nodes;i++)
    {
        printf("Node %d:",nodes[i].num);
        if(nodes[i].is_ground==1)
            printf("(Ground)");
        printf("\n");
    }

    //take input for simulation
    printf("\nEnter the simulation time: ");
    scanf("%f",&time);
    printf("Enter the time step: ");
    scanf("%f",&step);

    //simulate circuit
    printf("\nNode Voltages\n");
    current=0;
    for(i=0;i<(time/step);i++)
    {
        printf("\nTime: %.2f\n",i*step);
        for(j=0;j<n_elements;j++)
        {
            if(strcmp(elements[j].name,"R")==0)
            {
                float r=elements[j].value;
                float v=nodes[elements[j].node1].voltage-nodes[elements[j].node2].voltage;
                current=v/r;
                nodes[elements[j].node1].voltage-=current*step;
                nodes[elements[j].node2].voltage+=current*step;
                printf("Voltage across resistor %d: %.2f V\n",j+1,v);
                printf("Current through resistor %d: %.2f A\n",j+1,current);
            }
            else if(strcmp(elements[j].name,"C")==0)
            {
                float c=elements[j].value;
                float v=nodes[elements[j].node1].voltage-nodes[elements[j].node2].voltage;
                current=c*(v/step);
                nodes[elements[j].node1].voltage-=current*step;
                nodes[elements[j].node2].voltage+=current*step;
                printf("Voltage across capacitor %d: %.2f V\n",j+1,v);
                printf("Current through capacitor %d: %.2f A\n",j+1,current);
            }
        }
    }
    return 0;
}