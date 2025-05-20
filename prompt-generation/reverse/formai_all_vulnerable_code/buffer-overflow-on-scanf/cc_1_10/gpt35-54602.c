//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include<stdio.h>
#define MAX 100000
struct point{
    int x,y;
};
struct stack{
    int top;
    struct point stk_data[MAX];
};
struct point point_array[MAX],result[MAX];
int n,retval;
struct stack st;
int check_direction(struct point p1,struct point p2,struct point p3){
    int direction;
    direction=((p2.x-p1.x)*(p3.y-p1.y))-((p3.x-p1.x)*(p2.y-p1.y));
    if(direction>0) return 1; //clockwise direction
    if(direction<0) return 2; //anti-clockwise direction
    if(direction==0) return 0; //collinear direction
}
int compare(const void *a,const void *b){
    struct point *p1=(struct point*)a,*p2=(struct point*)b;
    int dir=check_direction(point_array[0],*p1,*p2);
    if(dir==0){
        if((p1->x+p1->y)>(p2->x+p2->y)) return 1;
        else return -1;
    }
    else if(dir==2) return -1;
    else if(dir==1) return 1;
}
void init(){
    while (st.top != -1) {
        st.top--;
    }
}
void push(struct point data){
    st.stk_data[++st.top]=data;
}
void display(struct point result[],int count){
    for(int i=0;i<count;i++){
       printf("(%d, %d)\n",result[i].x,result[i].y);
    } 
}
void calc_convex_hull(){
    struct point temp;
    int i,j,k=0;
    qsort(&point_array[0],n,sizeof(struct point),compare);
    push(point_array[0]);
    push(point_array[1]);
    for(i=2;i<n;i++){
        while(st.top>0 && check_direction(st.stk_data[st.top-1],st.stk_data[st.top],point_array[i])!=2){
            st.top--;
        }
        st.stk_data[++st.top]=point_array[i];
    }
    while(st.top>=0){
        result[k++]=st.stk_data[st.top--];
    }
    display(result,k);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&point_array[i].x,&point_array[i].y);
    }
    init();
    calc_convex_hull();
    return 0;
}