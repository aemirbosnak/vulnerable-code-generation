//Falcon-180B DATASET v1.0 Category: Data mining ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

struct customer
{
    char name[20];
    int age;
    float salary;
};

struct customer dataset[100];

void read_data()
{
    FILE *fp;
    fp=fopen("customer_data.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening file");
        exit(1);
    }
    int i=0;
    while(fscanf(fp,"%s %d %f",dataset[i].name,&dataset[i].age,&dataset[i].salary)==3)
    {
        i++;
    }
    fclose(fp);
}

void display_data(int start,int end)
{
    printf("\nName\tAge\tSalary\n");
    for(int i=start;i<=end;i++)
    {
        printf("%s\t%d\t%.2f\n",dataset[i].name,dataset[i].age,dataset[i].salary);
    }
}

void swap(struct customer *a,struct customer *b)
{
    struct customer temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void quick_sort(int start,int end)
{
    int partition;
    struct customer pivot;
    pivot=dataset[end];
    partition=partition_function(start,end,pivot);
    swap(&dataset[partition],&dataset[end]);
    quick_sort(start,partition-1);
    quick_sort(partition+1,end);
}

int partition_function(int start,int end,struct customer pivot)
{
    int partition=start-1;
    for(int i=start;i<=end-1;i++)
    {
        if(dataset[i].age>pivot.age)
        {
            partition++;
            swap(&dataset[partition],&dataset[i]);
        }
    }
    swap(&dataset[partition+1],&dataset[end]);
    return partition+1;
}

void main()
{
    int n,start,end;
    read_data();
    printf("\nEnter the number of customers to be displayed: ");
    scanf("%d",&n);
    start=0;
    end=n-1;
    display_data(start,end);
}